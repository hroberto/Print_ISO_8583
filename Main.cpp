

#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>


#define T_INT64 unsigned long long int


/**
 *
 **/
std::string printBinary(T_INT64 b1, const int __length = 0) {
    const unsigned int LEN = ( __length == 0 ? 64 : __length ); //( sizeof( b2 )*8 );
    T_INT64 masc = 0x01;
    masc <<=  ( LEN -1 );

    std::stringstream ss ;

    int achou = ( __length != 0 );
    int bit;
    for( int i = LEN -1 ; i >= 0 ; --i ) {
        bit = ( ( b1 & masc ) >> i );
        if ( bit ) {
            achou = 1;
        }
        if( achou ) {
            ss << bit;
        }
        masc >>= 1;
    }

    return ( ss.str() );
}


/**
 *
 **/
void setBit(T_INT64 & __byte, const int __bitISO) {
    T_INT64 v = 0x1;
    v <<= ( __bitISO - 1 );
    __byte |= v;
}

/**
 *
 **/
 std::string byteToHex(const T_INT64 & __n) {
     std::stringstream ss ;

     ss << std::uppercase << std::hex << __n;

     return ( ss.str() );
 }
/**
 *
 **/
void inverterMapaBits(T_INT64 b1, T_INT64 & b2, const int __length, int bitStart = 0  ) {
    b2 = 0x00;

    const int LEN = __length; //( sizeof( b2 )*8 );
    T_INT64 masc = ( 0x01 << bitStart );

    int bit;
    for( int i = bitStart ; i < LEN ; ++i ) {
        bit = ( ( b1 & masc ) >> i );
        b2 = ( ( b2 << 1) | bit );
        masc <<= 1;
    }
}

/**
 *
 **/
void inverterMapaBits(const int b1[], int b2[], const int __length, int bitStart = 0 )
{
    for ( int i = bitStart, j = __length - 1; j > -1; i++, j-- )
    {
        b2[i] = b1[j];
    }
}

/**
 *
 **/
const T_INT64 byteConvert2(const int b[], int __bitStart = 1, const int __length = 64 ) {
    T_INT64 ret = 0;
    T_INT64 mascara = 0x1;

    for (int i=__bitStart; i<=(__bitStart +  __length - 1 ); ++i ) {
        if ( b[i] == 1 ) {
            ret |= mascara;
        }
        mascara <<= 1;
    }
    return ( ret );
}


void teste_iso_fmr()
{
    std::cout << std::endl << "===== COM MATRIZ" << std::endl;

    T_INT64 primeiroMapaBits( 0x00000000 ) , segundoMapaBits( 0x00000000 );

    int bits[128];
    for ( int i = 1; i < 128; ++i ) {
        bits[ i ] = 0;
    }
    bits[ 24 ] = 1;
    bits[ 40 ] = 1;
    bits[ 42 ] = 1;
    bits[ 3 ] = 1;
    bits[ 11 ] = 1;
    bits[ 12 ] = 1;
    bits[ 60 ] = 1;
    bits[ 13 ] = 1;
    bits[ 24 ] = 1;
    bits[ 40 ] = 1;
    bits[ 65 ] = 1;


    inverterMapaBits( byteConvert2( bits, 1 ), primeiroMapaBits, 64 );
    inverterMapaBits( byteConvert2( bits, 65 ), segundoMapaBits,  64 );

    std::cout << __LINE__ << " - Mapa (1) Decimal [" << primeiroMapaBits << "]"  << " Hexadecimal ["  << byteToHex(primeiroMapaBits) << "]" << std::endl;
    std::cout << __LINE__ << " - Mapa (2) Decimal [" << segundoMapaBits << "]"  << " Hexadecimal ["  << byteToHex(segundoMapaBits) << "]" << std::endl;

    std::cout << std::endl;

}


//////////////////////////////////////////////////////////

void teste_iso_bms()
{
    // #if ( __cplusplus != __cplusplus_Cpp98 )

        T_INT64 myByte1( 0x00000000 ), myByte2( 0x00000000 );

        myByte1 = 0x00000000;
        // setBit( myByte1, 0 );
        setBit( myByte1, 1 );
        setBit( myByte1, 3 );
        setBit( myByte1, 7 );
        setBit( myByte1, 11 );
        setBit( myByte1, 12 );
        setBit( myByte1, 13 );
        setBit( myByte1, 24 );
        setBit( myByte1, 39 );
        setBit( myByte1, 41 );
        setBit( myByte1, 42 );
        setBit( myByte1, 48 );
        setBit( myByte1, 61 );
        setBit( myByte1, 62 );
        setBit( myByte1, 63 );
        setBit( myByte1, 64 );
        // setBit( myByte2, 65  - 64 );
        setBit( myByte2, 127 - 64 );

        T_INT64 primeiroMapaBits( 0x00000000 ) , segundoMapaBits( 0x00000000 );
        inverterMapaBits(myByte1, primeiroMapaBits, 64 );
        inverterMapaBits(myByte2, segundoMapaBits,  64 );

        std::cout << __LINE__ << " - Calculado Decimal [" << myByte1 << "]"  << " Hexadecimal ["  << byteToHex(myByte1) << "]" << std::endl;
        std::cout << __LINE__ << " - Mapa (1) Binary  [" << printBinary( primeiroMapaBits, 64 ) << "]" << std::endl;
        std::cout << __LINE__ << " - Mapa (1) Decimal [" << primeiroMapaBits << "]"  << " Hexadecimal ["  << byteToHex(primeiroMapaBits) << "]" << std::endl;
        std::cout << __LINE__ << " - Mapa (2) Decimal [" << segundoMapaBits << "]"  << " Hexadecimal ["  << byteToHex(segundoMapaBits) << "]" << std::endl;



    // #endif

    std::cout << std::endl << "===== COM MATRIZ" << std::endl;

    int bits[128];
    for ( int i = 1; i < 128; ++i ) {
        bits[ i ] = 0;
    }
    bits[ 1 ] = 1;
    bits[ 3 ] = 1;
    bits[ 7 ] = 1;
    bits[ 11 ] = 1;
    bits[ 12 ] = 1;
    bits[ 13 ] = 1;
    bits[ 24 ] = 1;
    bits[ 39 ] = 1;
    bits[ 41 ] = 1;
    bits[ 42 ] = 1;
    bits[ 48 ] = 1;
    bits[ 61 ] = 1;
    bits[ 62 ] = 1;
    bits[ 63 ] = 1;
    bits[ 64 ] = 1;
    // bits[ 65 ] = 1;
    bits[ 127 ] = 1;

    inverterMapaBits(byteConvert2( bits, 1 ), primeiroMapaBits, 64 );
    inverterMapaBits(byteConvert2( bits, 65 ), segundoMapaBits,  64 );

    myByte2 = byteConvert2( bits, 65 );

    std::cout << __LINE__ << " - Mapa (1) Decimal [" << primeiroMapaBits << "]"  << " Hexadecimal ["  << byteToHex(primeiroMapaBits) << "]" << std::endl;
    std::cout << __LINE__ << " - Mapa (2) Decimal [" << segundoMapaBits << "]"  << " Hexadecimal ["  << byteToHex(segundoMapaBits) << "]" << std::endl;

    std::cout << std::endl;
}




int main(int argc, char** argv)
{
    std::cout << "******* teste_iso_bms ***** \n";
    teste_iso_bms();

    std::cout << "******* teste_iso_fmr ***** \n";
    teste_iso_fmr();

    return 0;
}
