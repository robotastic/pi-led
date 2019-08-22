#include "led-module.h"
#include "led-matrix.h"

#ifndef FONT_MODULE_H_
#define FONT_MODULE_H_
char fontData[128][8] = { 
{ 0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00 },    // 0 :  
		//		|          |
		//		|          |
		//		|          |
		//		|          |
		//		|          |
		//		|          |
		//		|          |
		//		|          |

  { 0x00,  0x3E,  0x41,  0x55,  0x41,  0x55,  0x49,  0x3E },    // 1 : 
		//		|          |
		//		|   *****  |
		//		|  *     * |
		//		|  * * * * |
		//		|  *     * |
		//		|  * * * * |
		//		|  *  *  * |
		//		|   *****  |

  { 0x00,  0x3E,  0x7F,  0x6B,  0x7F,  0x6B,  0x77,  0x3E },    // 2 : 
		//		|          |
		//		|   *****  |
		//		|  ******* |
		//		|  ** * ** |
		//		|  ******* |
		//		|  ** * ** |
		//		|  *** *** |
		//		|   *****  |

  { 0x00,  0x22,  0x77,  0x7F,  0x7F,  0x3E,  0x1C,  0x08 },    // 3 : 
		//		|          |
		//		|   *   *  |
		//		|  *** *** |
		//		|  ******* |
		//		|  ******* |
		//		|   *****  |
		//		|    ***   |
		//		|     *    |

  { 0x00,  0x08,  0x1C,  0x3E,  0x7F,  0x3E,  0x1C,  0x08 },    // 4 : 
		//		|          |
		//		|     *    |
		//		|    ***   |
		//		|   *****  |
		//		|  ******* |
		//		|   *****  |
		//		|    ***   |
		//		|     *    |

  { 0x00,  0x08,  0x1C,  0x2A,  0x7F,  0x2A,  0x08,  0x1C },    // 5 : 
		//		|          |
		//		|     *    |
		//		|    ***   |
		//		|   * * *  |
		//		|  ******* |
		//		|   * * *  |
		//		|     *    |
		//		|    ***   |

  { 0x00,  0x08,  0x1C,  0x3E,  0x7F,  0x3E,  0x08,  0x1C },    // 6 : 
		//		|          |
		//		|     *    |
		//		|    ***   |
		//		|   *****  |
		//		|  ******* |
		//		|   *****  |
		//		|     *    |
		//		|    ***   |

  { 0x00,  0x00,  0x1C,  0x3E,  0x3E,  0x3E,  0x1C,  0x00 },    // 7 : 
		//		|          |
		//		|          |
		//		|    ***   |
		//		|   *****  |
		//		|   *****  |
		//		|   *****  |
		//		|    ***   |
		//		|          |

  { 0xFF,  0xFF,  0xE3,  0xC1,  0xC1,  0xC1,  0xE3,  0xFF },    // 8 : 
		//		| ******** |
		//		| ******** |
		//		| ***   ** |
		//		| **     * |
		//		| **     * |
		//		| **     * |
		//		| ***   ** |
		//		| ******** |

  { 0x00,  0x00,  0x1C,  0x22,  0x22,  0x22,  0x1C,  0x00 },    // 9 : 	
		//		|          |
		//		|          |
		//		|    ***   |
		//		|   *   *  |
		//		|   *   *  |
		//		|   *   *  |
		//		|    ***   |
		//		|          |

  { 0xFF,  0xFF,  0xE3,  0xDD,  0xDD,  0xDD,  0xE3,  0xFF },    // 10 : 

		//		| ******** |
		//		| ******** |
		//		| ***   ** |
		//		| ** *** * |
		//		| ** *** * |
		//		| ** *** * |
		//		| ***   ** |
		//		| ******** |

  { 0x00,  0x0F,  0x03,  0x05,  0x39,  0x48,  0x48,  0x30 },    // 11 : 
		//		|          |
		//		|     **** |
		//		|       ** |
		//		|      * * |
		//		|   ***  * |
		//		|  *  *    |
		//		|  *  *    |
		//		|   **     |

  { 0x00,  0x08,  0x3E,  0x08,  0x1C,  0x22,  0x22,  0x1C },    // 12 : 
		//		|          |
		//		|     *    |
		//		|   *****  |
		//		|     *    |
		//		|    ***   |
		//		|   *   *  |
		//		|   *   *  |
		//		|    ***   |

  { 0x00,  0x18,  0x14,  0x10,  0x10,  0x30,  0x70,  0x60 },    // 13 : 

		//		|          |
		//		|    **    |
		//		|    * *   |
		//		|    *     |
		//		|    *     |
		//		|   **     |
		//		|  ***     |
		//		|  **      |

  { 0x00,  0x0F,  0x19,  0x11,  0x13,  0x37,  0x76,  0x60 },    // 14 : 
		//		|          |
		//		|     **** |
		//		|    **  * |
		//		|    *   * |
		//		|    *  ** |
		//		|   ** *** |
		//		|  *** **  |
		//		|  **      |

  { 0x00,  0x08,  0x2A,  0x1C,  0x77,  0x1C,  0x2A,  0x08 },    // 15 : 
		//		|          |
		//		|     *    |
		//		|   * * *  |
		//		|    ***   |
		//		|  *** *** |
		//		|    ***   |
		//		|   * * *  |
		//		|     *    |

  { 0x00,  0x60,  0x78,  0x7E,  0x7F,  0x7E,  0x78,  0x60 },    // 16 : 
		//		|          |
		//		|  **      |
		//		|  ****    |
		//		|  ******  |
		//		|  ******* |
		//		|  ******  |
		//		|  ****    |
		//		|  **      |

  { 0x00,  0x03,  0x0F,  0x3F,  0x7F,  0x3F,  0x0F,  0x03 },    // 17 : 
		//		|          |
		//		|       ** |
		//		|     **** |
		//		|   ****** |
		//		|  ******* |
		//		|   ****** |
		//		|     **** |
		//		|       ** |

  { 0x00,  0x08,  0x1C,  0x2A,  0x08,  0x2A,  0x1C,  0x08 },    // 18 : 
		//		|          |
		//		|     *    |
		//		|    ***   |
		//		|   * * *  |
		//		|     *    |
		//		|   * * *  |
		//		|    ***   |
		//		|     *    |

  { 0x00,  0x66,  0x66,  0x66,  0x66,  0x00,  0x66,  0x66 },    // 19 : 
		//		|          |
		//		|  **  **  |
		//		|  **  **  |
		//		|  **  **  |
		//		|  **  **  |
		//		|          |
		//		|  **  **  |
		//		|  **  **  |

  { 0x00,  0x3F,  0x65,  0x65,  0x3D,  0x05,  0x05,  0x05 },    // 20 : 
		//		|          |
		//		|   ****** |
		//		|  **  * * |
		//		|  **  * * |
		//		|   **** * |
		//		|      * * |
		//		|      * * |
		//		|      * * |

  { 0x00,  0x0C,  0x32,  0x48,  0x24,  0x12,  0x4C,  0x30 },    // 21 : 
		//		|          |
		//		|     **   |
		//		|   **  *  |
		//		|  *  *    |
		//		|   *  *   |
		//		|    *  *  |
		//		|  *  **   |
		//		|   **     |

  { 0x00,  0x00,  0x00,  0x00,  0x00,  0x7F,  0x7F,  0x7F },    // 22 : 
		//		|          |
		//		|          |
		//		|          |
		//		|          |
		//		|          |
		//		|  ******* |
		//		|  ******* |
		//		|  ******* |

  { 0x00,  0x08,  0x1C,  0x2A,  0x08,  0x2A,  0x1C,  0x3E },    // 23 : 
		//		|          |
		//		|     *    |
		//		|    ***   |
		//		|   * * *  |
		//		|     *    |
		//		|   * * *  |
		//		|    ***   |
		//		|   *****  |

  { 0x00,  0x08,  0x1C,  0x3E,  0x7F,  0x1C,  0x1C,  0x1C },    // 24 : 
		//		|          |
		//		|     *    |
		//		|    ***   |
		//		|   *****  |
		//		|  ******* |
		//		|    ***   |
		//		|    ***   |
		//		|    ***   |

  { 0x00,  0x1C,  0x1C,  0x1C,  0x7F,  0x3E,  0x1C,  0x08 },    // 25 : 
		//		|          |
		//		|    ***   |
		//		|    ***   |
		//		|    ***   |
		//		|  ******* |
		//		|   *****  |
		//		|    ***   |
		//		|     *    |

  { 0x00,  0x08,  0x0C,  0x7E,  0x7F,  0x7E,  0x0C,  0x08 },    // 26 : 
		//		|          |
		//		|     *    |
		//		|     **   |
		//		|  ******  |
		//		|  ******* |
		//		|  ******  |
		//		|     **   |
		//		|     *    |

  { 0x00,  0x08,  0x18,  0x3F,  0x7F,  0x3F,  0x18,  0x08 },    // 27 : 
		//		|          |
		//		|     *    |
		//		|    **    |
		//		|   ****** |
		//		|  ******* |
		//		|   ****** |
		//		|    **    |
		//		|     *    |

  { 0x00,  0x00,  0x00,  0x70,  0x70,  0x70,  0x7F,  0x7F },    // 28 : 
		//		|          |
		//		|          |
		//		|          |
		//		|  ***     |
		//		|  ***     |
		//		|  ***     |
		//		|  ******* |
		//		|  ******* |

  { 0x00,  0x00,  0x14,  0x22,  0x7F,  0x22,  0x14,  0x00 },    // 29 : 
		//		|          |
		//		|          |
		//		|    * *   |
		//		|   *   *  |
		//		|  ******* |
		//		|   *   *  |
		//		|    * *   |
		//		|          |

  { 0x00,  0x08,  0x1C,  0x1C,  0x3E,  0x3E,  0x7F,  0x7F },    // 30 : 
		//		|          |
		//		|     *    |
		//		|    ***   |
		//		|    ***   |
		//		|   *****  |
		//		|   *****  |
		//		|  ******* |
		//		|  ******* |

  { 0x00,  0x7F,  0x7F,  0x3E,  0x3E,  0x1C,  0x1C,  0x08 },    // 31 : 
		//		|          |
		//		|  ******* |
		//		|  ******* |
		//		|   *****  |
		//		|   *****  |
		//		|    ***   |
		//		|    ***   |
		//		|     *    |

  { 0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00 },    // 32 :  
		//		|          |
		//		|          |
		//		|          |
		//		|          |
		//		|          |
		//		|          |
		//		|          |
		//		|          |

  { 0x00,  0x18,  0x3C,  0x3C,  0x18,  0x18,  0x00,  0x18 },    // 33 : !
		//		|          |
		//		|    **    |
		//		|   ****   |
		//		|   ****   |
		//		|    **    |
		//		|    **    |
		//		|          |
		//		|    **    |

  { 0x00,  0x36,  0x36,  0x14,  0x00,  0x00,  0x00,  0x00 },    // 34 : "
		//		|          |
		//		|   ** **  |
		//		|   ** **  |
		//		|    * *   |
		//		|          |
		//		|          |
		//		|          |
		//		|          |

  { 0x00,  0x36,  0x36,  0x7F,  0x36,  0x7F,  0x36,  0x36 },    // 35 : #
		//		|          |
		//		|   ** **  |
		//		|   ** **  |
		//		|  ******* |
		//		|   ** **  |
		//		|  ******* |
		//		|   ** **  |
		//		|   ** **  |

  { 0x00,  0x08,  0x1E,  0x20,  0x1C,  0x02,  0x3C,  0x08 },    // 36 : $
		//		|          |
		//		|     *    |
		//		|    ****  |
		//		|   *      |
		//		|    ***   |
		//		|       *  |
		//		|   ****   |
		//		|     *    |

  { 0x00,  0x60,  0x66,  0x0C,  0x18,  0x30,  0x66,  0x06 },    // 37 : %
		//		|          |
		//		|  **      |
		//		|  **  **  |
		//		|     **   |
		//		|    **    |
		//		|   **     |
		//		|  **  **  |
		//		|      **  |

  { 0x00,  0x3C,  0x66,  0x3C,  0x28,  0x65,  0x66,  0x3F },    // 38 : &
		//		|          |
		//		|   ****   |
		//		|  **  **  |
		//		|   ****   |
		//		|   * *    |
		//		|  **  * * |
		//		|  **  **  |
		//		|   ****** |

  { 0x00,  0x18,  0x18,  0x18,  0x30,  0x00,  0x00,  0x00 },    // 39 : '
		//		|          |
		//		|    **    |
		//		|    **    |
		//		|    **    |
		//		|   **     |
		//		|          |
		//		|          |
		//		|          |

  { 0x00,  0x60,  0x30,  0x18,  0x18,  0x18,  0x30,  0x60 },    // 40 : (
		//		|          |
		//		|  **      |
		//		|   **     |
		//		|    **    |
		//		|    **    |
		//		|    **    |
		//		|   **     |
		//		|  **      |

  { 0x00,  0x06,  0x0C,  0x18,  0x18,  0x18,  0x0C,  0x06 },    // 41 : )
		//		|          |
		//		|      **  |
		//		|     **   |
		//		|    **    |
		//		|    **    |
		//		|    **    |
		//		|     **   |
		//		|      **  |

  { 0x00,  0x00,  0x36,  0x1C,  0x7F,  0x1C,  0x36,  0x00 },    // 42 : *
		//		|          |
		//		|          |
		//		|   ** **  |
		//		|    ***   |
		//		|  ******* |
		//		|    ***   |
		//		|   ** **  |
		//		|          |

  { 0x00,  0x00,  0x08,  0x08,  0x3E,  0x08,  0x08,  0x00 },    // 43 : +
		//		|          |
		//		|          |
		//		|     *    |
		//		|     *    |
		//		|   *****  |
		//		|     *    |
		//		|     *    |
		//		|          |

  { 0x00,  0x00,  0x00,  0x00,  0x30,  0x30,  0x30,  0x60 },    // 44 : ,
		//		|          |
		//		|          |
		//		|          |
		//		|          |
		//		|   **     |
		//		|   **     |
		//		|   **     |
		//		|  **      |

  { 0x00,  0x00,  0x00,  0x00,  0x3C,  0x00,  0x00,  0x00 },    // 45 : -
		//		|          |
		//		|          |
		//		|          |
		//		|          |
		//		|   ****   |
		//		|          |
		//		|          |
		//		|          |

  { 0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x60,  0x60 },    // 46 : .
		//		|          |
		//		|          |
		//		|          |
		//		|          |
		//		|          |
		//		|          |
		//		|  **      |
		//		|  **      |

  { 0x00,  0x00,  0x06,  0x0C,  0x18,  0x30,  0x60,  0x00 },    // 47 : /
		//		|          |
		//		|          |
		//		|      **  |
		//		|     **   |
		//		|    **    |
		//		|   **     |
		//		|  **      |
		//		|          |

  { 0x00,  0x3C,  0x66,  0x6E,  0x76,  0x66,  0x66,  0x3C },    // 48 : 0
		//		|          |
		//		|   ****   |
		//		|  **  **  |
		//		|  ** ***  |
		//		|  *** **  |
		//		|  **  **  |
		//		|  **  **  |
		//		|   ****   |

  { 0x00,  0x18,  0x18,  0x38,  0x18,  0x18,  0x18,  0x7E },    // 49 : 1
		//		|          |
		//		|    **    |
		//		|    **    |
		//		|   ***    |
		//		|    **    |
		//		|    **    |
		//		|    **    |
		//		|  ******  |

  { 0x00,  0x3C,  0x66,  0x06,  0x0C,  0x30,  0x60,  0x7E },    // 50 : 2
		//		|          |
		//		|   ****   |
		//		|  **  **  |
		//		|      **  |
		//		|     **   |
		//		|   **     |
		//		|  **      |
		//		|  ******  |

  { 0x00,  0x3C,  0x66,  0x06,  0x1C,  0x06,  0x66,  0x3C },    // 51 : 3
		//		|          |
		//		|   ****   |
		//		|  **  **  |
		//		|      **  |
		//		|    ***   |
		//		|      **  |
		//		|  **  **  |
		//		|   ****   |

  { 0x00,  0x0C,  0x1C,  0x2C,  0x4C,  0x7E,  0x0C,  0x0C },    // 52 : 4
		//		|          |
		//		|     **   |
		//		|    ***   |
		//		|   * **   |
		//		|  *  **   |
		//		|  ******  |
		//		|     **   |
		//		|     **   |

  { 0x00,  0x7E,  0x60,  0x7C,  0x06,  0x06,  0x66,  0x3C },    // 53 : 5
		//		|          |
		//		|  ******  |
		//		|  **      |
		//		|  *****   |
		//		|      **  |
		//		|      **  |
		//		|  **  **  |
		//		|   ****   |

  { 0x00,  0x3C,  0x66,  0x60,  0x7C,  0x66,  0x66,  0x3C },    // 54 : 6
		//		|          |
		//		|   ****   |
		//		|  **  **  |
		//		|  **      |
		//		|  *****   |
		//		|  **  **  |
		//		|  **  **  |
		//		|   ****   |

  { 0x00,  0x7E,  0x66,  0x0C,  0x0C,  0x18,  0x18,  0x18 },    // 55 : 7
		//		|          |
		//		|  ******  |
		//		|  **  **  |
		//		|     **   |
		//		|     **   |
		//		|    **    |
		//		|    **    |
		//		|    **    |

  { 0x00,  0x3C,  0x66,  0x66,  0x3C,  0x66,  0x66,  0x3C },    // 56 : 8
		//		|          |
		//		|   ****   |
		//		|  **  **  |
		//		|  **  **  |
		//		|   ****   |
		//		|  **  **  |
		//		|  **  **  |
		//		|   ****   |

  { 0x00,  0x3C,  0x66,  0x66,  0x3E,  0x06,  0x66,  0x3C },    // 57 : 9
		//		|          |
		//		|   ****   |
		//		|  **  **  |
		//		|  **  **  |
		//		|   *****  |
		//		|      **  |
		//		|  **  **  |
		//		|   ****   |

  { 0x00,  0x00,  0x18,  0x18,  0x00,  0x18,  0x18,  0x00 },    // 58 : :
		//		|          |
		//		|          |
		//		|    **    |
		//		|    **    |
		//		|          |
		//		|    **    |
		//		|    **    |
		//		|          |

  { 0x00,  0x00,  0x18,  0x18,  0x00,  0x18,  0x18,  0x30 },    // 59 : ;
		//		|          |
		//		|          |
		//		|    **    |
		//		|    **    |
		//		|          |
		//		|    **    |
		//		|    **    |
		//		|   **     |

  { 0x00,  0x06,  0x0C,  0x18,  0x30,  0x18,  0x0C,  0x06 },    // 60 : <
		//		|          |
		//		|      **  |
		//		|     **   |
		//		|    **    |
		//		|   **     |
		//		|    **    |
		//		|     **   |
		//		|      **  |

  { 0x00,  0x00,  0x00,  0x3C,  0x00,  0x3C,  0x00,  0x00 },    // 61 : =
		//		|          |
		//		|          |
		//		|          |
		//		|   ****   |
		//		|          |
		//		|   ****   |
		//		|          |
		//		|          |

  { 0x00,  0x60,  0x30,  0x18,  0x0C,  0x18,  0x30,  0x60 },    // 62 : >
		//		|          |
		//		|  **      |
		//		|   **     |
		//		|    **    |
		//		|     **   |
		//		|    **    |
		//		|   **     |
		//		|  **      |

  { 0x00,  0x3C,  0x66,  0x06,  0x1C,  0x18,  0x00,  0x18 },    // 63 : ?
		//		|          |
		//		|   ****   |
		//		|  **  **  |
		//		|      **  |
		//		|    ***   |
		//		|    **    |
		//		|          |
		//		|    **    |

  { 0x00,  0x38,  0x44,  0x5C,  0x58,  0x42,  0x3C,  0x00 },    // 64 : @
		//		|          |
		//		|   ***    |
		//		|  *   *   |
		//		|  * ***   |
		//		|  * **    |
		//		|  *    *  |
		//		|   ****   |
		//		|          |

  { 0x00,  0x3C,  0x66,  0x66,  0x7E,  0x66,  0x66,  0x66 },    // 65 : A
		//		|          |
		//		|   ****   |
		//		|  **  **  |
		//		|  **  **  |
		//		|  ******  |
		//		|  **  **  |
		//		|  **  **  |
		//		|  **  **  |

  { 0x00,  0x7C,  0x66,  0x66,  0x7C,  0x66,  0x66,  0x7C },    // 66 : B
		//		|          |
		//		|  *****   |
		//		|  **  **  |
		//		|  **  **  |
		//		|  *****   |
		//		|  **  **  |
		//		|  **  **  |
		//		|  *****   |

  { 0x00,  0x3C,  0x66,  0x60,  0x60,  0x60,  0x66,  0x3C },    // 67 : C
		//		|          |
		//		|   ****   |
		//		|  **  **  |
		//		|  **      |
		//		|  **      |
		//		|  **      |
		//		|  **  **  |
		//		|   ****   |

  { 0x00,  0x7C,  0x66,  0x66,  0x66,  0x66,  0x66,  0x7C },    // 68 : D
		//		|          |
		//		|  *****   |
		//		|  **  **  |
		//		|  **  **  |
		//		|  **  **  |
		//		|  **  **  |
		//		|  **  **  |
		//		|  *****   |

  { 0x00,  0x7E,  0x60,  0x60,  0x7C,  0x60,  0x60,  0x7E },    // 69 : E
		//		|          |
		//		|  ******  |
		//		|  **      |
		//		|  **      |
		//		|  *****   |
		//		|  **      |
		//		|  **      |
		//		|  ******  |

  { 0x00,  0x7E,  0x60,  0x60,  0x7C,  0x60,  0x60,  0x60 },    // 70 : F
		//		|          |
		//		|  ******  |
		//		|  **      |
		//		|  **      |
		//		|  *****   |
		//		|  **      |
		//		|  **      |
		//		|  **      |

  { 0x00,  0x3C,  0x66,  0x60,  0x60,  0x6E,  0x66,  0x3C },    // 71 : G
		//		|          |
		//		|   ****   |
		//		|  **  **  |
		//		|  **      |
		//		|  **      |
		//		|  ** ***  |
		//		|  **  **  |
		//		|   ****   |

  { 0x00,  0x66,  0x66,  0x66,  0x7E,  0x66,  0x66,  0x66 },    // 72 : H
		//		|          |
		//		|  **  **  |
		//		|  **  **  |
		//		|  **  **  |
		//		|  ******  |
		//		|  **  **  |
		//		|  **  **  |
		//		|  **  **  |

  { 0x00,  0x3C,  0x18,  0x18,  0x18,  0x18,  0x18,  0x3C },    // 73 : I
		//		|          |
		//		|   ****   |
		//		|    **    |
		//		|    **    |
		//		|    **    |
		//		|    **    |
		//		|    **    |
		//		|   ****   |

  { 0x00,  0x1E,  0x0C,  0x0C,  0x0C,  0x6C,  0x6C,  0x38 },    // 74 : J
		//		|          |
		//		|    ****  |
		//		|     **   |
		//		|     **   |
		//		|     **   |
		//		|  ** **   |
		//		|  ** **   |
		//		|   ***    |

  { 0x00,  0x66,  0x6C,  0x78,  0x70,  0x78,  0x6C,  0x66 },    // 75 : K
		//		|          |
		//		|  **  **  |
		//		|  ** **   |
		//		|  ****    |
		//		|  ***     |
		//		|  ****    |
		//		|  ** **   |
		//		|  **  **  |

  { 0x00,  0x60,  0x60,  0x60,  0x60,  0x60,  0x60,  0x7E },    // 76 : L
		//		|          |
		//		|  **      |
		//		|  **      |
		//		|  **      |
		//		|  **      |
		//		|  **      |
		//		|  **      |
		//		|  ******  |

  { 0x00,  0x63,  0x77,  0x7F,  0x6B,  0x63,  0x63,  0x63 },    // 77 : M
		//		|          |
		//		|  **   ** |
		//		|  *** *** |
		//		|  ******* |
		//		|  ** * ** |
		//		|  **   ** |
		//		|  **   ** |
		//		|  **   ** |

  { 0x00,  0x63,  0x73,  0x7B,  0x6F,  0x67,  0x63,  0x63 },    // 78 : N
		//		|          |
		//		|  **   ** |
		//		|  ***  ** |
		//		|  **** ** |
		//		|  ** **** |
		//		|  **  *** |
		//		|  **   ** |
		//		|  **   ** |

  { 0x00,  0x3C,  0x66,  0x66,  0x66,  0x66,  0x66,  0x3C },    // 79 : O
		//		|          |
		//		|   ****   |
		//		|  **  **  |
		//		|  **  **  |
		//		|  **  **  |
		//		|  **  **  |
		//		|  **  **  |
		//		|   ****   |

  { 0x00,  0x7C,  0x66,  0x66,  0x66,  0x7C,  0x60,  0x60 },    // 80 : P
		//		|          |
		//		|  *****   |
		//		|  **  **  |
		//		|  **  **  |
		//		|  **  **  |
		//		|  *****   |
		//		|  **      |
		//		|  **      |

  { 0x00,  0x3C,  0x66,  0x66,  0x66,  0x6E,  0x3C,  0x06 },    // 81 : Q
		//		|          |
		//		|   ****   |
		//		|  **  **  |
		//		|  **  **  |
		//		|  **  **  |
		//		|  ** ***  |
		//		|   ****   |
		//		|      **  |

  { 0x00,  0x7C,  0x66,  0x66,  0x7C,  0x78,  0x6C,  0x66 },    // 82 : R
		//		|          |
		//		|  *****   |
		//		|  **  **  |
		//		|  **  **  |
		//		|  *****   |
		//		|  ****    |
		//		|  ** **   |
		//		|  **  **  |

  { 0x00,  0x3C,  0x66,  0x60,  0x3C,  0x06,  0x66,  0x3C },    // 83 : S
		//		|          |
		//		|   ****   |
		//		|  **  **  |
		//		|  **      |
		//		|   ****   |
		//		|      **  |
		//		|  **  **  |
		//		|   ****   |

  { 0x00,  0x7E,  0x5A,  0x18,  0x18,  0x18,  0x18,  0x18 },    // 84 : T
		//		|          |
		//		|  ******  |
		//		|  * ** *  |
		//		|    **    |
		//		|    **    |
		//		|    **    |
		//		|    **    |
		//		|    **    |

  { 0x00,  0x66,  0x66,  0x66,  0x66,  0x66,  0x66,  0x3E },    // 85 : U
		//		|          |
		//		|  **  **  |
		//		|  **  **  |
		//		|  **  **  |
		//		|  **  **  |
		//		|  **  **  |
		//		|  **  **  |
		//		|   *****  |

  { 0x00,  0x66,  0x66,  0x66,  0x66,  0x66,  0x3C,  0x18 },    // 86 : V
		//		|          |
		//		|  **  **  |
		//		|  **  **  |
		//		|  **  **  |
		//		|  **  **  |
		//		|  **  **  |
		//		|   ****   |
		//		|    **    |

  { 0x00,  0x63,  0x63,  0x63,  0x6B,  0x7F,  0x77,  0x63 },    // 87 : W
		//		|          |
		//		|  **   ** |
		//		|  **   ** |
		//		|  **   ** |
		//		|  ** * ** |
		//		|  ******* |
		//		|  *** *** |
		//		|  **   ** |

  { 0x00,  0x63,  0x63,  0x36,  0x1C,  0x36,  0x63,  0x63 },    // 88 : X
		//		|          |
		//		|  **   ** |
		//		|  **   ** |
		//		|   ** **  |
		//		|    ***   |
		//		|   ** **  |
		//		|  **   ** |
		//		|  **   ** |

  { 0x00,  0x66,  0x66,  0x66,  0x3C,  0x18,  0x18,  0x18 },    // 89 : Y
		//		|          |
		//		|  **  **  |
		//		|  **  **  |
		//		|  **  **  |
		//		|   ****   |
		//		|    **    |
		//		|    **    |
		//		|    **    |

  { 0x00,  0x7E,  0x06,  0x0C,  0x18,  0x30,  0x60,  0x7E },    // 90 : Z
		//		|          |
		//		|  ******  |
		//		|      **  |
		//		|     **   |
		//		|    **    |
		//		|   **     |
		//		|  **      |
		//		|  ******  |

  { 0x00,  0x1E,  0x18,  0x18,  0x18,  0x18,  0x18,  0x1E },    // 91 : [
		//		|          |
		//		|    ****  |
		//		|    **    |
		//		|    **    |
		//		|    **    |
		//		|    **    |
		//		|    **    |
		//		|    ****  |

  { 0x00,  0x00,  0x60,  0x30,  0x18,  0x0C,  0x06,  0x00 },    // 92 : 
		//		|          |
		//		|          |
		//		|  **      |
		//		|   **     |
		//		|    **    |
		//		|     **   |
		//		|      **  |
		//		|          |

  { 0x00,  0x78,  0x18,  0x18,  0x18,  0x18,  0x18,  0x78 },    // 93 : ]
		//		|          |
		//		|  ****    |
		//		|    **    |
		//		|    **    |
		//		|    **    |
		//		|    **    |
		//		|    **    |
		//		|  ****    |

  { 0x00,  0x08,  0x14,  0x22,  0x41,  0x00,  0x00,  0x00 },    // 94 : ^
		//		|          |
		//		|     *    |
		//		|    * *   |
		//		|   *   *  |
		//		|  *     * |
		//		|          |
		//		|          |
		//		|          |

  { 0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x7F },    // 95 : _
		//		|          |
		//		|          |
		//		|          |
		//		|          |
		//		|          |
		//		|          |
		//		|          |
		//		|  ******* |

  { 0x00,  0x0C,  0x0C,  0x06,  0x00,  0x00,  0x00,  0x00 },    // 96 : `
		//		|          |
		//		|     **   |
		//		|     **   |
		//		|      **  |
		//		|          |
		//		|          |
		//		|          |
		//		|          |

  { 0x00,  0x00,  0x00,  0x3C,  0x06,  0x3E,  0x66,  0x3E },    // 97 : a
		//		|          |
		//		|          |
		//		|          |
		//		|   ****   |
		//		|      **  |
		//		|   *****  |
		//		|  **  **  |
		//		|   *****  |

  { 0x00,  0x60,  0x60,  0x60,  0x7C,  0x66,  0x66,  0x7C },    // 98 : b
		//		|          |
		//		|  **      |
		//		|  **      |
		//		|  **      |
		//		|  *****   |
		//		|  **  **  |
		//		|  **  **  |
		//		|  *****   |

  { 0x00,  0x00,  0x00,  0x3C,  0x66,  0x60,  0x66,  0x3C },    // 99 : c
		//		|          |
		//		|          |
		//		|          |
		//		|   ****   |
		//		|  **  **  |
		//		|  **      |
		//		|  **  **  |
		//		|   ****   |

  { 0x00,  0x06,  0x06,  0x06,  0x3E,  0x66,  0x66,  0x3E },    // 100 : d
		//		|          |
		//		|      **  |
		//		|      **  |
		//		|      **  |
		//		|   *****  |
		//		|  **  **  |
		//		|  **  **  |
		//		|   *****  |

  { 0x00,  0x00,  0x00,  0x3C,  0x66,  0x7E,  0x60,  0x3C },    // 101 : e
		//		|          |
		//		|          |
		//		|          |
		//		|   ****   |
		//		|  **  **  |
		//		|  ******  |
		//		|  **      |
		//		|   ****   |

  { 0x00,  0x1C,  0x36,  0x30,  0x30,  0x7C,  0x30,  0x30 },    // 102 : f
		//		|          |
		//		|    ***   |
		//		|   ** **  |
		//		|   **     |
		//		|   **     |
		//		|  *****   |
		//		|   **     |
		//		|   **     |

  { 0x00,  0x00,  0x3E,  0x66,  0x66,  0x3E,  0x06,  0x3C },    // 103 : g
		//		|          |
		//		|          |
		//		|   *****  |
		//		|  **  **  |
		//		|  **  **  |
		//		|   *****  |
		//		|      **  |
		//		|   ****   |

  { 0x00,  0x60,  0x60,  0x60,  0x7C,  0x66,  0x66,  0x66 },    // 104 : h
		//		|          |
		//		|  **      |
		//		|  **      |
		//		|  **      |
		//		|  *****   |
		//		|  **  **  |
		//		|  **  **  |
		//		|  **  **  |

  { 0x00,  0x00,  0x18,  0x00,  0x18,  0x18,  0x18,  0x3C },    // 105 : i
		//		|          |
		//		|          |
		//		|    **    |
		//		|          |
		//		|    **    |
		//		|    **    |
		//		|    **    |
		//		|   ****   |

  { 0x00,  0x0C,  0x00,  0x0C,  0x0C,  0x6C,  0x6C,  0x38 },    // 106 : j
		//		|          |
		//		|     **   |
		//		|          |
		//		|     **   |
		//		|     **   |
		//		|  ** **   |
		//		|  ** **   |
		//		|   ***    |

  { 0x00,  0x60,  0x60,  0x66,  0x6C,  0x78,  0x6C,  0x66 },    // 107 : k
		//		|          |
		//		|  **      |
		//		|  **      |
		//		|  **  **  |
		//		|  ** **   |
		//		|  ****    |
		//		|  ** **   |
		//		|  **  **  |

  { 0x00,  0x18,  0x18,  0x18,  0x18,  0x18,  0x18,  0x18 },    // 108 : l
		//		|          |
		//		|    **    |
		//		|    **    |
		//		|    **    |
		//		|    **    |
		//		|    **    |
		//		|    **    |
		//		|    **    |

  { 0x00,  0x00,  0x00,  0x63,  0x77,  0x7F,  0x6B,  0x6B },    // 109 : m
		//		|          |
		//		|          |
		//		|          |
		//		|  **   ** |
		//		|  *** *** |
		//		|  ******* |
		//		|  ** * ** |
		//		|  ** * ** |

  { 0x00,  0x00,  0x00,  0x7C,  0x7E,  0x66,  0x66,  0x66 },    // 110 : n
		//		|          |
		//		|          |
		//		|          |
		//		|  *****   |
		//		|  ******  |
		//		|  **  **  |
		//		|  **  **  |
		//		|  **  **  |

  { 0x00,  0x00,  0x00,  0x3C,  0x66,  0x66,  0x66,  0x3C },    // 111 : o
		//		|          |
		//		|          |
		//		|          |
		//		|   ****   |
		//		|  **  **  |
		//		|  **  **  |
		//		|  **  **  |
		//		|   ****   |

  { 0x00,  0x00,  0x7C,  0x66,  0x66,  0x7C,  0x60,  0x60 },    // 112 : p
		//		|          |
		//		|          |
		//		|  *****   |
		//		|  **  **  |
		//		|  **  **  |
		//		|  *****   |
		//		|  **      |
		//		|  **      |

  { 0x00,  0x00,  0x3C,  0x6C,  0x6C,  0x3C,  0x0D,  0x0F },    // 113 : q
		//		|          |
		//		|          |
		//		|   ****   |
		//		|  ** **   |
		//		|  ** **   |
		//		|   ****   |
		//		|     ** * |
		//		|     **** |

  { 0x00,  0x00,  0x00,  0x7C,  0x66,  0x66,  0x60,  0x60 },    // 114 : r
		//		|          |
		//		|          |
		//		|          |
		//		|  *****   |
		//		|  **  **  |
		//		|  **  **  |
		//		|  **      |
		//		|  **      |

  { 0x00,  0x00,  0x00,  0x3E,  0x40,  0x3C,  0x02,  0x7C },    // 115 : s
		//		|          |
		//		|          |
		//		|          |
		//		|   *****  |
		//		|  *       |
		//		|   ****   |
		//		|       *  |
		//		|  *****   |

  { 0x00,  0x00,  0x18,  0x18,  0x7E,  0x18,  0x18,  0x18 },    // 116 : t
		//		|          |
		//		|          |
		//		|    **    |
		//		|    **    |
		//		|  ******  |
		//		|    **    |
		//		|    **    |
		//		|    **    |

  { 0x00,  0x00,  0x00,  0x66,  0x66,  0x66,  0x66,  0x3E },    // 117 : u
		//		|          |
		//		|          |
		//		|          |
		//		|  **  **  |
		//		|  **  **  |
		//		|  **  **  |
		//		|  **  **  |
		//		|   *****  |

  { 0x00,  0x00,  0x00,  0x00,  0x66,  0x66,  0x3C,  0x18 },    // 118 : v
		//		|          |
		//		|          |
		//		|          |
		//		|          |
		//		|  **  **  |
		//		|  **  **  |
		//		|   ****   |
		//		|    **    |

  { 0x00,  0x00,  0x00,  0x63,  0x6B,  0x6B,  0x6B,  0x3E },    // 119 : w
		//		|          |
		//		|          |
		//		|          |
		//		|  **   ** |
		//		|  ** * ** |
		//		|  ** * ** |
		//		|  ** * ** |
		//		|   *****  |

  { 0x00,  0x00,  0x00,  0x66,  0x3C,  0x18,  0x3C,  0x66 },    // 120 : x
		//		|          |
		//		|          |
		//		|          |
		//		|  **  **  |
		//		|   ****   |
		//		|    **    |
		//		|   ****   |
		//		|  **  **  |

  { 0x00,  0x00,  0x00,  0x66,  0x66,  0x3E,  0x06,  0x3C },    // 121 : y
		//		|          |
		//		|          |
		//		|          |
		//		|  **  **  |
		//		|  **  **  |
		//		|   *****  |
		//		|      **  |
		//		|   ****   |

  { 0x00,  0x00,  0x00,  0x3C,  0x0C,  0x18,  0x30,  0x3C },    // 122 : z
		//		|          |
		//		|          |
		//		|          |
		//		|   ****   |
		//		|     **   |
		//		|    **    |
		//		|   **     |
		//		|   ****   |

  { 0x00,  0x0E,  0x18,  0x18,  0x30,  0x18,  0x18,  0x0E },    // 123 : {
		//		|          |
		//		|     ***  |
		//		|    **    |
		//		|    **    |
		//		|   **     |
		//		|    **    |
		//		|    **    |
		//		|     ***  |

  { 0x00,  0x18,  0x18,  0x18,  0x00,  0x18,  0x18,  0x18 },    // 124 : |
		//		|          |
		//		|    **    |
		//		|    **    |
		//		|    **    |
		//		|          |
		//		|    **    |
		//		|    **    |
		//		|    **    |

  { 0x00,  0x70,  0x18,  0x18,  0x0C,  0x18,  0x18,  0x70 },    // 125 : }
		//		|          |
		//		|  ***     |
		//		|    **    |
		//		|    **    |
		//		|     **   |
		//		|    **    |
		//		|    **    |
		//		|  ***     |

  { 0x00,  0x00,  0x00,  0x3A,  0x6C,  0x00,  0x00,  0x00 },    // 126 : ~
		//		|          |
		//		|          |
		//		|          |
		//		|   *** *  |
		//		|  ** **   |
		//		|          |
		//		|          |
		//		|          |

  { 0x00,  0x08,  0x1C,  0x36,  0x63,  0x41,  0x41,  0x7F }    // 127 : 
		//		|          |
		//		|     *    |
		//		|    ***   |
		//		|   ** **  |
		//		|  **   ** |
		//		|  *     * |
		//		|  *     * |
		//		|  ******* |


};
#endif
using namespace std;
LedMatrix::LedMatrix(int m) {
	int i;
	moduleNum = m;
	_width = 32*moduleNum;
	_height = 8;
modules = new LedModule[m];
	fontWidth = 8;


if (wiringPiSPISetup(0, 25000000) <0)
  cout <<  "SPI Setup Failed: " <<  strerror(errno) << endl;

 if (wiringPiSetup() == -1)
   exit(1);
 pinMode(0, OUTPUT);
 pinMode(1, OUTPUT);
 pinMode(2, OUTPUT);
 pinMode(3, OUTPUT);


for (i=0; i < m; i++) {
	modules[i].setChip(i);
	modules[i].init();
}

}

LedMatrix::~LedMatrix() {
	delete []modules;
}

void LedMatrix::drawPixel(uint8_t x, uint8_t y, uint8_t color) {
  if (y >= _height) return;
  if (x >= _width) return;

  uint8_t m;
  // figure out which matrix controller it is
  m = x / 32;
	x %= 32;
	modules[m].drawPixel(x, y, color);
 }

void LedMatrix::writeMatrix() {
	
 for (int i=0; i < moduleNum; i++) {
 	modules[i].writeMatrix();
 }
 	//printMatrix();
}

void LedMatrix::printMatrix() {
	unsigned char output[8][128+1];

	for (int i=0; i < moduleNum; i++) {
		modules[i].printMatrix(output);
	}


	for (int i=0; i < _height; i++ ){
		output[i][_width] = '\0';
		//cout << strlen(output[i]) << endl;
		cout << output[i] << endl;
		//printf("%s \n",output[i]);
	}
}

void LedMatrix::clearMatrix() {
	
 for (int i=0; i < moduleNum; i++) {
 	modules[i].clearMatrix();
 }
}

void LedMatrix::scrollMatrixOnce(int offset) {
  int n;

if (offset >= fontWidth)
	return;

uint8_t temp = offscreen[offset];

for(n=moduleNum;n>0;n--) {
temp = modules[n-1].scrollMatrixOnce(temp); // n-1 since the matrix is 0 based
}
 

  writeMatrix();
  usleep(12500);
}

void LedMatrix::drawChar(char c, int offset, uint8_t *buf) {
  int row, col,x,y;
  memset(buf,0,8);
     for (row=0; row<8; row++) {
	uint8_t z = fontData[(int8_t) c][row];
	for(col=0; col<8; col++) {
	  x = offset * fontWidth + col;
	  y = 8 - row;

	  if ((z &0x80) != 0) {
	    *(buf + x) = *(buf + x) | (1 << y); // find the bit in the byte that needs to be turned on;
	  }else {
	    *(buf + x) = *(buf + x) & ~(1 << y); // find the bit in the byte that needs to be turned on;
	  }
	
	  z = z <<1;
	}
     }
}

void LedMatrix::printMessage(char const *message) {
	int i;
	int msg_len = strlen(message);

	for (i=0; i < moduleNum; i++) {
		modules[i].init();
	} 
	 clearMatrix();
	if (msg_len > 32) {
		msg_len = 32;
		//message[32] = '\0';
	}
	for (i=0; i < msg_len; i++ ) {
		int module = floor(i/4);
		uint8_t* matrix = modules[module].getMatrix();
		drawChar(message[i], i%4, matrix);
	}
	for (i=0; i < moduleNum; i++) {
		modules[i].writeMatrix();
	}
	printMatrix(); 
}

void LedMatrix::writeMessage(char const *message) {
  int display_len = 16;//width*displays/font_width;
  int i, pix;
  int msg_len = strlen(message);


for (i=0; i < moduleNum; i++) {
	modules[i].init();
} 

 clearMatrix();
	cout <<  "[";
  for (i=0; i < msg_len; i++ ) {

      char c = message[i];
      drawChar(c, 0, offscreen);

	cout << c;

      for (pix = 0; pix < fontWidth; pix++){
		scrollMatrixOnce(pix);
      }
  }
  
  for (i=0; i < display_len; i++ ) {

      char c = ' ';
      drawChar(c, 0, offscreen);

	  cout << ' ';

      for (pix = 0; pix < fontWidth; pix++){
  		scrollMatrixOnce(pix);
      }
  }
 cout <<  "]" << endl;
}

