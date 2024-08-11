#include <iostream>
#include <string>
#include <vector>

const int GRID_HEIGHT = 20;
const int GRID_WIDTH = 20;
const int NORTH = 0;
const int EAST = 1;
const int SOUTH = 2;
const int WEST = 3;

const int NUM_ANTS = 100;
const int NUM_DOODLES = 5;
const int ANT_BREED_TIMER = 3;
const int DOODLE_BREED_TIMER = 8;
const int DOODLE_STARVE_TIMER = 3;
const char ANT_CHAR = 'o';
const char DOODLE_CHAR = 'X';
const char NULL_CHAR = '-';

class Grid;

struct Location {
  int row;
  int col;

  Location(int Row, int Col) : row(Row), col(Col) {}
};


class Creature {
private:
  char type;
  Location loc;
  int breed_timer = 0;
public:
  Creature(char Type, const Location Loc) : type(Type), loc(Loc) {}
  virtual ~Creature() {}

  Location get_location() const { return this -> loc; }
  void set_location(const Location& new_loc) { this -> loc = new_loc; }
  char get_type() const { return this -> type; }
  void set_type(char new_type) {this -> type = new_type; }
  int get_breed_timer() const { return this -> breed_timer; }
  void set_breed_timer(int new_breed_timer) { this -> breed_timer = new_breed_timer; }
  virtual int get_starve_timer() const { return -1; }
  virtual void set_starve_timer() {}

  virtual void move(Grid& grid);
  virtual void breed(Grid& grid);
  virtual void starve(Grid& grid) {}
  virtual void iterate(Grid& grid) = 0;

  friend std::ostream& operator<<(std::ostream& outs, const Creature& rhs);
};
std::ostream& operator<<(std::ostream& outs, const Creature& rhs) {
  if (rhs.type == 'a')
    outs<<ANT_CHAR;
  else if (rhs.type == 'd')
    outs<<DOODLE_CHAR;
  
  return outs;
}


class Ant : public Creature {
public:
  Ant(const Location Loc) : Creature('a', Loc) {}
  ~Ant() {}

  void iterate(Grid& grid);
};


class Doodle : public Creature {
private:
  int starve_timer = 0;
public:
  Doodle(const Location Loc) : Creature('d', Loc) {}
  ~Doodle() {}

  int get_starve_timer() const { return this -> starve_timer; }
  void set_starve_timer(int new_starve_timer) { this -> starve_timer = new_starve_timer; } 

  void move(Grid& grid);
  void starve(Grid& grid);
  void iterate(Grid& grid);
};


class Grid {
private:
  int rows, cols, num_ants, num_doodles;
  std::vector<std::vector<Creature*>> grid;
  int step = 0;
public:
  Grid(int Rows=GRID_HEIGHT, int Cols=GRID_WIDTH, int Num_Ants=NUM_ANTS, int Num_Doodles=NUM_DOODLES) : rows(Rows), cols(Cols), num_ants(Num_Ants), num_doodles(Num_Doodles) { initialize_grid(); } 
  ~Grid();

  int get_step() { return this -> step; }
  void set_step(int new_step) { this -> step = new_step; }
  void populate_grid();
  void initialize_grid();
  void print_grid() const;
  bool assert_empty(const Location location) const;
  bool assert_ant(const Location location) const;
  std::vector<Location> get_adjacent_locations(const Location location) const;
  std::vector<Location> get_empty_adjacent_locations(const Location location) const;
  std::vector<Location> get_adjacent_ants(const Location location) const;
  void move_creature(Creature* creature, const Location new_location);
  void remove_creature(const Location location);
  void iterate();
};
Grid::~Grid() {
  Creature* creature;
  for (int row = 0; row < this-> rows; row++) {
    for (int col = 0; col < this -> cols; col++) {
      creature = this -> grid[row][col];
      if (creature != nullptr)
        delete creature;
        grid[row][col] = nullptr;
    }
  }
}
void Grid::populate_grid() {
  int row, col;
  for (int i = 0; i < this -> num_ants; i++) {
    row = rand() % this -> rows;
    col = rand() % this -> cols;
    while (this -> grid[row][col] != nullptr) {
      row = rand() % this -> rows;
      col = rand() % this -> cols;
    }
    this -> grid[row][col] = new Ant(Location(row, col));
  }
  for (int i = 0; i < this -> num_doodles; i++) {
    row = rand() % this -> rows;
    col = rand() % this -> cols;
    while (this -> grid[row][col] != nullptr) {
      row = rand() % this -> rows;
      col = rand() % this -> cols;
    }
    this -> grid[row][col] = new Doodle(Location(row, col));
  }
}
void Grid::initialize_grid() {
  for (int row = 0; row < this -> rows; row++) {
    std::vector<Creature*> temp;
    for (int col = 0; col < this -> cols; col++) {
      temp.push_back(nullptr);
    }
    this -> grid.push_back(temp);
  }
  populate_grid();
}
void Grid::print_grid() const {
  Creature* elem;
  std::cout<<"World at time "<<this -> step<<":\n\n";
  for (int row = 0; row < this -> rows; row++) {
    for (int col = 0; col < this -> cols; col++) {
      elem = this -> grid[row][col];
      if (elem == nullptr)
        std::cout<<NULL_CHAR;
      else
        std::cout<<*elem;
      std::cout<<" ";
    }
    std::cout<<"\n";
  }
  std::cout<<std::endl;
}
bool Grid::assert_empty(const Location location) const {
  if (location.row >= 0 && location.row < this -> rows && location.col >= 0 && location.col < this -> cols) {
    if (this -> grid[location.row][location.col] == nullptr)
      return true;
  }
  return false;
}
bool Grid::assert_ant(const Location location) const {
  if (location.row >= 0 && location.row < this -> rows && location.col >= 0 && location.col < this -> cols) {
    if (this -> grid[location.row][location.col] != nullptr && this -> grid[location.row][location.col] -> get_type() == 'a')
      return true;
  }
  return false;
}
std::vector<Location> Grid::get_adjacent_locations(const Location location) const {
  std::vector<Location> adjacent_locations;
  adjacent_locations.push_back(Location(location.row+1, location.col));
  adjacent_locations.push_back(Location(location.row-1, location.col));
  adjacent_locations.push_back(Location(location.row, location.col+1));
  adjacent_locations.push_back(Location(location.row, location.col-1));

  return adjacent_locations;
}
std::vector<Location> Grid::get_empty_adjacent_locations(const Location location) const {
  std::vector<Location> untested_locations, validated_locations;
  untested_locations = get_adjacent_locations(location);
  for (Location test_location : untested_locations) {
    if (assert_empty(test_location))
      validated_locations.push_back(test_location);
  }

  return validated_locations;
}
std::vector<Location> Grid::get_adjacent_ants(const Location location) const {
  std::vector<Location> untested_locations, validated_locations;
  untested_locations = get_adjacent_locations(location);
  for (Location test_location : untested_locations) {
    if (assert_ant(test_location))
      validated_locations.push_back(test_location);
  }

  return validated_locations;
}
void Grid::move_creature(Creature* creature, const Location new_location) {
  Location old_location = creature -> get_location();
  creature -> set_location(new_location);
  this -> grid[old_location.row][old_location.col] = nullptr;
  this -> grid[new_location.row][new_location.col] = creature;
}
void Grid::remove_creature(const Location location) {
  Creature* creature = this -> grid[location.row][location.col];
  delete creature;
  this -> grid[location.row][location.col] = nullptr;
}
void Grid::iterate() {
  std::vector<std::vector<Creature*>> snapshot = this -> grid;
  for (int row = 0; row < this -> rows; row++) {
    for (int col = 0; col < this -> cols; col++) {
      Creature* creature = snapshot[row][col];
      if (creature == nullptr)
        continue;
      else if (creature -> get_type() == 'd')
        creature -> iterate(*this);
    }
  }

  snapshot = this -> grid;
  for (int row = 0; row < this -> rows; row++) {
    for (int col = 0; col < this -> cols; col++) {
      Creature* creature = snapshot[row][col];
      if (creature == nullptr)
        continue;
      else if (creature -> get_type() == 'a')
        creature -> iterate(*this);
    }
  }

  set_step(get_step() + 1);
  print_grid();
}


void Creature::move(Grid& grid) {
  std::vector<Location> empty_adjacent_locations = grid.get_empty_adjacent_locations(this -> loc);
  int num_locations = empty_adjacent_locations.size();
  if (num_locations) {
    Location new_location = empty_adjacent_locations[rand() % num_locations];
    grid.move_creature(this, new_location);
  }
  this -> breed_timer++;
}
void Creature::breed(Grid& grid) {
  char creature_type = this -> get_type();
  if (this -> get_type() == 'a' && this -> get_breed_timer() < ANT_BREED_TIMER)
    return;
  else if (this -> get_type() == 'd' && this -> get_breed_timer() < DOODLE_BREED_TIMER)
    return;

  std::vector<Location> empty_adjacent_locations = grid.get_empty_adjacent_locations(this -> get_location());
  int num_locations = empty_adjacent_locations.size();
  if (num_locations) {
    Location new_location = empty_adjacent_locations[rand() % num_locations];
    if (this -> get_type() == 'a') {
      Ant* ant = new Ant(new_location);
      grid.move_creature(ant, new_location);
    }
    else {
      Doodle* doodle = new Doodle(new_location);
      grid.move_creature(doodle, new_location);
    }
    this -> set_breed_timer(0);
  }
}

void Ant::iterate(Grid& grid) {
  this -> move(grid);
  this -> breed(grid);
}

void Doodle::move(Grid& grid) {
  int num_locations;
  std::vector<Location> empty_adjacent_locations, adjacent_ants;
  adjacent_ants = grid.get_adjacent_ants(this -> get_location());
  num_locations = adjacent_ants.size();
  if (num_locations) {
    Location new_location = adjacent_ants[rand() % num_locations];
    grid.remove_creature(new_location);
    grid.move_creature(this, new_location);
    this -> set_starve_timer(0);
  }
  else {
    empty_adjacent_locations = grid.get_empty_adjacent_locations(this -> get_location());
    num_locations = empty_adjacent_locations.size();
    if (num_locations) {
      Location new_location = empty_adjacent_locations[rand() % num_locations];
      grid.move_creature(this, new_location);
    }
    this -> set_starve_timer(this -> get_starve_timer() + 1);
  }

  this -> set_breed_timer(this -> get_breed_timer() + 1);
}
void Doodle::starve(Grid& grid) {
  if (this -> get_starve_timer() < DOODLE_STARVE_TIMER)
    return;
  
  grid.remove_creature(this -> get_location());
}
void Doodle::iterate(Grid& grid) {
  this -> move(grid);
  this -> breed(grid);
  this -> starve(grid);
}


int main() {
  srand(time(NULL));

  Grid grid(GRID_HEIGHT, GRID_WIDTH);
  grid.print_grid();
  std::cout<<"Press ENTER to begin\n";
  std::cin.get();
  while (true) {
    grid.iterate();
    std::cout<<"";
    std::cout<<"Press ENTER to continue\n";
    std::cin.get();
  }

  return 0;
}
