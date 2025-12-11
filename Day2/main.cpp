#include <iostream>
#include <string>
#include <fstream>

long long int globalSum = 0;

void add_sum (long int num) {
    globalSum += num;
}

long int find_length(long int length) {
    int i = 0;
    while (length > 0) {
        length = length/10;
        i++;
    }
    length = i;
    return length;
}

int check_range(long int min, long int max) {
    printf("Checking range: %ld - %ld\n", min, max);
    long int length = 0;
    for (long int i = min; i <= max; i++) {
       // printf("%d\n", i);
        length = find_length(i);
        //printf("Length: %ld\n", length);
        long int temp = i;
        long int arr[length];
        if (length % 2 == 0) {
            for (int j = 0; j < length; j++) {
                arr[length-1-j] = temp % 10;
                temp = temp/10;
            }
           long int sum1 = 0, sum2 = 0;
            for (int j = 0; j < length; j++) {
                if (j >= length/2) {
                    sum2 = sum2*10 + arr[j];
                }
                else {
                    sum1 = sum1*10 + arr[j];
                }
            }
            if (sum1 == sum2) {
               // printf("sum1: %d, sum2: %d, i: %d\n", sum1, sum2, i);
                add_sum(i);
            }
        }
    }
    return 0;
}

int main(){
    std::ifstream file("values.txt");
        if (!file.is_open()) {
            std::cerr<< "Can't open file" << std::endl;
            return 1;
        }
    char ch;
    long int num1 = 0, num2 = 0, x, i = 0;
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