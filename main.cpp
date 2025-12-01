#include <iostream>
#include <string>
#include <fstream>
std::string names[5000];

int wheel_position = 50;

int find_value(std::string input) {
    switch (input.size()) {
        case 2:
            return input[1] -'0';
        case 3:
            return (input[1]-'0')*10 + input[2]-'0';
        case 4:
            return (input[1]-'0')*100 + (input[2]-'0')*10 + input[3]-'0';
        case 5:
            return (input[1]-'0')*1000 + (input[2]-'0')*100 + (input[3]-'0')*10 + input[4]-'0';
    }
    return 0;
}

int wheel(std::string input) {
    int value = find_value(input);
    int counter = 0;

    for (int tick = 0; tick < value; tick++) {
        if (input[0] == 'R') {
           // std::cout << "R: " << tick << std::endl;
            wheel_position = (wheel_position + 1) % 100;
          //  std::cout << "Wheel: " << wheel_position << std::endl;
        } else if (input[0] == 'L') {
           // std::cout << "L: " << tick << std::endl;
            wheel_position = (wheel_position - 1) % 100;
            if (wheel_position < 0) {
                wheel_position += 100;
                if (wheel_position < 0) {
                    wheel_position *= -1;
                }
            }
          //  std::cout << "Wheel: " << wheel_position << std::endl;
        }
        if (wheel_position == 0) {
            counter++;
        }
    }
    return counter;
}

int main() {
 std::ifstream file("values.txt");
    if (!file.is_open()) {
        std::cerr << "Can't open values.txt" << std::endl;
        return 1;
    }

    std::string word;
    int count_zero = 0;
    for (int i = 0; file >> word; i++) {
        std::cout << count_zero << std::endl;
       count_zero += wheel(word);
    }

    std::cout << "Count: " << count_zero << "\n";


    return 0;
}