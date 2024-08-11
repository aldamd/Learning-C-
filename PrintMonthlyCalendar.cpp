#include <iostream>
#include <string>

const int DAYSINWEEK = 7;

int leap_year(int year) {
  if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    return 29;
  else
    return 28;
}

int printMonthCalender(int numOfDays, int startingDay) {
  int cur_day = 1;
  //print days of the week
  std::cout<<"Mon   Tue   Wed   Thr   Fri   Sat   Sun"<<std::endl;

  //print spaces before starting day
  for (int i = 1; i <= ((DAYSINWEEK - 1) * (startingDay - 1)); i++) {
    std::cout<<" ";
  }
    
  //print rest of first line
  for (int i = 1; i <= ((DAYSINWEEK + 1) - startingDay); i++) {
    std::cout<<cur_day<<"     ";
    cur_day++;
  }
  std::cout<<std::endl;
  
  //print rest of the month
  int weekday = 1;
  for (int i = 1; i <= (numOfDays - ((DAYSINWEEK + 1) - startingDay)); i++) {
    if (cur_day < 10)
      std::cout<<cur_day<<"     ";
    else
      std::cout<<cur_day<<"    ";

    cur_day++;
    weekday++;

    //reset weekday location and add a new line if passing sunday
    if (weekday == (DAYSINWEEK + 1)) {
      weekday = 1;
      if (i != numOfDays - ((DAYSINWEEK + 1) - startingDay))
        std::cout<<std::endl;
    }
  }

  std::cout<<std::endl<<std::endl;

  return weekday;
}

void printYearCalendar(int year, int startingDay) {
  std::cout<<"January "<<year<<std::endl;
  startingDay = printMonthCalender(31, startingDay);

  std::cout<<"February "<<year<<std::endl;
  startingDay = printMonthCalender(leap_year(year), startingDay);

  std::cout<<"March "<<year<<std::endl;
  startingDay = printMonthCalender(31, startingDay);

  std::cout<<"April "<<year<<std::endl;
  startingDay = printMonthCalender(30, startingDay);

  std::cout<<"May "<<year<<std::endl;
  startingDay = printMonthCalender(31, startingDay);

  std::cout<<"June "<<year<<std::endl;
  startingDay = printMonthCalender(30, startingDay);

  std::cout<<"July "<<year<<std::endl;
  startingDay = printMonthCalender(31, startingDay);

  std::cout<<"August "<<year<<std::endl;
  startingDay = printMonthCalender(31, startingDay);

  std::cout<<"September "<<year<<std::endl;
  startingDay = printMonthCalender(30, startingDay);

  std::cout<<"October "<<year<<std::endl;
  startingDay = printMonthCalender(31, startingDay);

  std::cout<<"November "<<year<<std::endl;
  startingDay = printMonthCalender(30, startingDay);

  std::cout<<"December "<<year<<std::endl;
  startingDay = printMonthCalender(31, startingDay);
}

int main() {
  int year;
  int startingDay;
  std::cout<<"Please enter calendar year: "; std::cin>>year;
  std::cout<<"Please enter which day of the week the first day starts on (1-7 for Mon-Sun): "; std::cin>>startingDay;

  printYearCalendar(year, startingDay);

  return 0;
}
