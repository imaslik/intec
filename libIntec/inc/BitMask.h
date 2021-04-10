#ifndef __BITMASK_H_
#define __BITMASK_H_

typedef unsigned int       U32;
typedef unsigned long long U64;

class CBitMask
{
public:
    // Set bit (mask) to target (value)
    // Input  value: 00100000
    // Masked value: 00002000
    // ----------------------
    // Return value: 00102000
    static inline U32 bitSet (U32& value, U32 mask) {return (value |=  mask);}

    // Clear bit (mask) at a target (value)
    // Input  value: 0000000F
    // Masked value: 00000003
    // ----------------------
    // Return value: 0000000C
    static inline U32 bitClr (U32& value, U32 mask) {return (value &= ~mask);}

    // Flip bit (mask) at a target (value)
    // Input  value: 00000030
    // Masked value: 00000FF0
    // ----------------------
    // Return value: 00000FC0
    static inline U32 bitFlip(U32& value, U32 mask) {return (value ^=  mask);}

    // Set bit at a requested (bitNum)
    // bit position: 3
    // ----------------------
    // Return value: 00000004
    static inline U32 bitMask(U32 bitNum)            {return (1<<bitNum);}

    // Set bit mask from bit (start) and up to bit (end)
    // Start position: 4
    // End position:   7
    // ----------------------
    // Return value: 000000F0
    static inline U32 bitMask(U32 start, U32 end) {
        return ((end-start) == 31) ? 0xFFFFFFFF : bitRow(end-start+1)<<start;
    }

    // Test whether bit (mask) at a target (value) is turned
    // Input  value: 000000F0
    // Masked value: 000000C0
    // ----------------------
    // Return value: true
    static inline bool bitTest(U32 value, U32 mask) {return (value & mask) ? 1 : 0;}

    // Count bit number at the target (value)
    // Input  value: 00000F11
    // ----------------------
    // Return value: 6
    static inline U32 bitCount(U32 value)
    {
        U32 tmp = value - ((value >> 1) & 033333333333) - ((value >> 2) & 011111111111);
        return ((tmp + (tmp >> 3)) & 030707070707) % 63;
    }

    // Extract bit field [(start),(end)] from a target (value)
    // Input  value: 0000F370
    // Start position: 4
    // End position:   11
    // ----------------------
    // Return value: 00000037
    static inline U32 bfGet(U32 value, U32 start, U32 end)
    {
        return (value >> start) & bitRow(end-start+1);
    }

    // Set bit field [(start),(end)] at a target (value) with (fValue)
    // Input  value: 00000000
    // Field  value: 0xFF
    // Start position: 4
    // End position:   7
    // ----------------------
    // Return value: 000000F0
    static inline U32 bfSet (U32& value, U32 fValue, U32 start, U32 end)
    {
        bitClr(value,bitMask(start,end)); // Clear destination bits
        return value |= ((fValue << start) & bitMask(start,end));
    }

    // Set bit (mask) to a target (value) from position (start)
    // Input  value: 00000110
    // Masked value: 0xFF
    // Start position: 4
    // ----------------------
    // Return value: 00000FF0
    static inline U32 bfSet (U32& value, U32 mask, U32 start) {return (value |=  (mask << start));}


private:
    // Create bit mask value of (length) size
    // length: 8
    // ----------------------
    // Return value: 000000FF
    static inline U32 bitRow(U32 length) {return bitMask(length) - 1;}

};


namespace BitMask
{
    // Set bit (mask) to target (value)
    static inline U32 bitSet (U32& value, U32 mask)
                {return CBitMask::bitSet(value,mask);}

    // Clear bit (mask) at a target (value)
    static inline U32 bitClr (U32& value, U32 mask)
                {return CBitMask::bitClr(value,mask);}

    // Flip bit (mask) at a target (value)
    static inline U32 bitFlip(U32& value, U32 mask)
                {return CBitMask::bitFlip(value,mask);}

    // Set bit at a requested (bitNum)
    static inline U32 bitMask(U32 bitNum)
                {return CBitMask::bitMask(bitNum);}

    // Set bit mask from bit (start) and up to bit (end)
    static inline U32 bitMask(U32 start, U32 end)
                {return CBitMask::bitMask(start,end);}

    // Count bit number at the target (value)
    static inline U32 bitCount(U32 value)
                {return CBitMask::bitCount(value);}

    // Test whether bit (mask) at a target (value) is turned
    static inline bool bitTest(U32 value, U32 mask)
                {return CBitMask::bitTest(value,mask);}

    // Extract bit field [(start),(end)] from a target (value)
    static inline U32 bfGet (U32 value, U32 start, U32 end)
                {return CBitMask::bfGet(value,start,end);}

    // Set bit field [(start),(end)] at a target (value) with (fValue)
    static inline U32 bfSet (U32& value, U32 fValue, U32 start, U32 end)
                {return CBitMask::bfSet(value,fValue,start, end);}

    // Set bit (mask) to a target (value) from position (start)
    static inline U32 bfSet (U32& value, U32 mask, U32 start)
                {return CBitMask::bfSet(value,mask,start);}
}

#endif // __BITMASK_H_
