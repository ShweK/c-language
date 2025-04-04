int decode(){

    int i = -1;
    float rand_val = 2.5; //floating encoding uses the IEEE 754 standard, 1bit signed, 8bit exponent, 23 bit mantessa and bias value is 127== 32 bit(4bytes)
    double val = 2.5; // double precision uses the IEEE 754 std, 1 bit signed, 11 bit exponent, 52 bit mantessa == 64 bit , bias value is 1023
    return 0;
}

/*Encoding for integers is with 2's complement, 
unsigned char = 255 CPU will consider it 
but for further computation the number will be stored in 2's complement form i.e when you do 255+1 will result to 0*/