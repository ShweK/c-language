/*You are given two 32-bit unsigned integers, A and B.
They are supposed to be identical hardware register values, but due to a transmission error, at most one bit may have flipped.

Your task is to:

Determine if A and B differ in exactly one bit.

Return the bit position (0-indexed from LSB) where the bit differs.

If more than one bit differs or they are identical, return -1.

*/

int findDifferingBit(uint32_t A, uint32_t B){

    int pos =0;

    uint32_t diff = A^B;
    //if identical or more than 1 bit set
    if(diff ==0 || (diff & (diff-1))!=0) return -1; 
    //logic for position of the differed bit
    while((diff & 1) == 0)
    {
        pos++;
        diff = diff>>1;
    }

    return pos;

}