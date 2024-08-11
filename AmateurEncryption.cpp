#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

const int ARR_SIZE = 10;
const int PIN_SIZE = 5;
const int MAX_RAND = 3;
const int PASS_ARR[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
const int PIN[] = {1, 2, 3, 4, 5};
const int ASCII2DEC = 48;

void create_encrypted_array(int encr_arr[]) {
    //create encrypted string of length array_size (values range from 1-3)
    std::srand(std::time(0));

    for (int idx = 0; idx < ARR_SIZE; idx++) {
        encr_arr[idx] = (std::rand() % MAX_RAND + 1);
    }
}

void get_encrypted_pin(int encr_pin[], int encr_arr[]) {
    //creates an encrypted version of the given pin number
    int pin_elem, pass_arr_elem;
    for (int pin_idx = 0; pin_idx < PIN_SIZE; pin_idx++) {
        pin_elem = PIN[pin_idx];
        for (int pass_idx = 0; pass_idx < ARR_SIZE; pass_idx++) {
            pass_arr_elem = PASS_ARR[pass_idx];
            if (pass_arr_elem == pin_elem) {
                encr_pin[pin_idx] = encr_arr[pass_idx];
                continue;
            }
        }
    }
}

void print_user_prompt(int encr_arr[]) {
    std::cout<<"Please enter your PIN according to the following mapping: "<<std::endl;

    std::cout<<"PIN:\t";
    for (int idx = 0; idx < ARR_SIZE; idx++) {
        std::cout<<PASS_ARR[idx]<<" ";
    }
    std::cout<<std::endl;

    std::cout<<"NUM:\t";
    for (int idx = 0; idx < ARR_SIZE; idx++) {
        std::cout<<encr_arr[idx]<<" ";
    }
    std::cout<<std::endl;
}

int main() {
    //create encrypted password mapping
    int encr_arr[ARR_SIZE];
    create_encrypted_array(encr_arr);

    //get encrypted PIN
    int encr_pin[PIN_SIZE];
    get_encrypted_pin(encr_pin, encr_arr);

    //print PIN and encrypted PIN for user reference
    print_user_prompt(encr_arr);

    std::string input_pin;
    std::cin>>input_pin;
    //convert string to integer array
    int input_arr[PIN_SIZE];
    int elem;
    for (int idx = 0; idx < PIN_SIZE; idx++) {
        input_arr[idx] = input_pin[idx] - ASCII2DEC;
    }

    //take user input pin and compare it to the encrypted pin
    for (int idx = 0; idx < PIN_SIZE; idx++) {
        if (input_arr[idx] != encr_pin[idx]) {
            std::cout<<"Your PIN is not correct"<<std::endl;
            return 0;
        }
    }
    std::cout<<"Your PIN is correct"<<std::endl;

    return 0;
}
