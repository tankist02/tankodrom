// ShiftOr algorithm to find a short substring in a text. Maximum substring length is 63 bytes.

#include <iostream>
#include <map>
#include <cstring>

int index(const char * text, const char * pattern) {
    unsigned long state = 0;
    unsigned long mask [256] = {0};
    int patlen = strlen(pattern);
    // Pattern is too short or too long
    if (patlen == 0 || patlen > 63) {
        return -1;
    }
    // Initialize mask table for each letter in the pattern
    for (int i = 0; i < patlen; i++) {
	    unsigned int ind = pattern[i] & 0xff;
        mask[ind] = mask[ind] | (1 << i);
    }
    int textlen = strlen(text);
    for (int i = 0; i < textlen; i++) {
        // Update state by shifting it and masking with the record from table
	    unsigned int ind = text[i] & 0xff; 
        state = (state << 1) + 1;
        state = state & mask[ind];
        if ((state & (1 << (patlen - 1))) != 0) {
            // It's a match!
            return (i - patlen + 1);
        }
    }
    // No match found
    return -1;
}

int main()
{
    int pos = index("helloworld", "low");
    std::cout << "'low' in 'helloworld' found at position " << pos << std::endl;
    return 0;
}

