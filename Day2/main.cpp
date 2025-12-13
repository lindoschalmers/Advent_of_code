#include <iostream>
#include <string>
#include <fstream>

//PART 2, ALSO COUNT ID's LIKE 111, 123123123

long long int globalSum = 0;

void add_sum (long long int num) {
    globalSum += num;
}

long long int find_length(long long int length) {
    int i = 0;
    while (length > 0) {
        length = length/10;
        i++;
    }
    length = i;
    return length;
}

int has_repeating_pattern(long long int length, long long int *arr) {
    for (int patternLen = 1; patternLen < length; patternLen++) {
        if (length % patternLen == 0) {
            int isRepeating = 1;

            //Check if pattern repeats
            for (int i = patternLen; i < length; i++) {
                if (arr[i] != arr[i % patternLen]) {
                    isRepeating = 0;
                    break;
                }
            }
            if (isRepeating) {
                return 1;
            }
        }
    }
    return 0;
}

void check_range(long long int min, long long int max) {
    printf("Checking range: %lld - %lld\n", min, max);
    long long int length = 0;
    for (long long int i = min; i <= max; i++) {
        // printf("%d\n", i);
        length = find_length(i);
        //printf("Length: %ld\n", length);
        long long int temp = i;
        long long int arr[length];

        for (int j = 0; j < length; j++) {
            arr[length-1-j] = temp % 10;
            temp = temp/10;
        }
        if (has_repeating_pattern(length, arr)) {
            add_sum(i);
        }
    }
}

int main(){
    std::ifstream file("values.txt");
        if (!file.is_open()) {
            std::cerr<< "Can't open file" << std::endl;
            return 1;
        }
    char ch;
    long long int num1 = 0, num2 = 0, x, i = 0;
    while (file.get(ch)) {
        if (ch == '-') {
            while (file.get(ch)) {
                if (ch == ',' || ch == '\n') {
                    check_range(num1, num2);
                    i = 1;
                    break;
                }
                if (ch != ' ' && ch != ',') {
                    x = ch - '0';
                    num2 = num2 * 10 + x;
                }
            }
        }
        if (i == 1) {
            num1 = 0;
            num2 = 0;
            i = 0;
        }
        if (ch != ',' && ch != '-' && ch != ' ') {
            x = ch - '0';
            num1 = num1 * 10 + x;
        }
    }
    printf("Global Sum: %lld\n", globalSum);

    return 0;
}