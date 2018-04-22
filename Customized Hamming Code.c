#include <stdio.h>
#include <string.h>
#include <math.h>

int exponent_calc(int exponent);
int bit_converter(int bit);

int main(){
    // All the global variable will be defined here
    int count = 0;
    char text[200];
    char check_text;

    printf("Welcome to Hamming Code (Demo Version)\n");

    while (1){
        printf("[Bit count = %d] Please type in the bit: ", count+1);
        scanf(" %c", &check_text);
        if(check_text == '1' || check_text == '0')
            text[count] = check_text;
        else{
            printf("\n%c is not a bit. Program will stop recieving data.\n\n", check_text);
            break;
        }
        count++;
    }
    printf("Your input message is: %s\n\n", text);

// Entering Parity Count stage //
    int data_count = strlen(text)-1; // Backslash 0 is manually removed.
    int parity_count = exponent_calc(data_count) + 1;
    int hamming_count = data_count + parity_count;
    printf("There will be a total of: \n%d parity bit(s)\t| %d data bit(s)\nTotal of %d bit(s) will be kept\n\n", parity_count,data_count,hamming_count);

// Entering the encryption stage //
    int skip_length = 1;
    int check_count = 0;
    int current_parity=0;
    hamming_count--;

    for (current_parity=0;current_parity<parity_count;current_parity++){
      printf("P%d contains [ ", current_parity+1);

        for (int i = current_parity;i<hamming_count;i++){
            for (int m = i;m<skip_length;m++){

                check_count = check_count + text[m];
                printf("%c(D%d) ", text[m],m);
            }
        }

        check_count = bit_converter(check_count);
        printf("]. Which parity #%d, bit equals to %d.\n",current_parity+1,check_count);
        check_count = 0;
  }

}

int exponent_calc(int exponent){
  int j = 1;
    for (int i=0;i<exponent;i++){
      if (j == exponent)
          return i;
      else
          j = j*2;
    }
}

int bit_converter(int bit){
    return bit%2;
}
