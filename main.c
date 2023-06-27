#include <string.h>

#define SCREEN_BUFFER_START      0x4000
#define ATTR_SCREEN_BUFFER_START 0x5800

static const unsigned char image[] = {
0xa1,0xff,0xa1,0xb8,0xbf,0xff,0xfb,0xff,0x80,0xfa,0x98,0x00,0xff,0x00,0x83,0x03,
0x01,0x7f,0xdf,0x82,0xdb,0xb0,0x41,0x81,0x10,0xb8,0x7f,0xcd,0x08,0xde,0xd4,0xaa,
0xaa,0xab,0xba,0x80,0x20,0x23,0x40,0x02,0xf8,0xf4,0x97,0x52,0x38,0x01,0x1a,0x01,
0xb8,0x01,0x80,0x00,0xa7,0xab,0xff,0xfe,0xdc,0xca,0xb5,0xff,0xab,0xb2,0x80,0xff,
0x02,0xef,0xbb,0x8a,0xac,0x98,0x74,0xa3,0x33,0x28,0xb8,0x41,0xa9,0xc1,0x00,0xaf,
0xaf,0xbf,0xba,0xb6,0xd3,0x92,0xc1,0x00,0x20,0x26,0xff,0xff,0x9b,0x92,0xaf,0xe0,
0x08,0x02,0xa0,0x2a,0xa6,0x00,0x13,0x21,0xab,0x03,0xee,0xeb,0xaa,0xff,0xbe,0xea,
0xbf,0xb9,0xcf,0xf2,0x81,0xa4,0x01,0xdf,0xfe,0xaa,0xff,0xef,0xee,0xc0,0x15,0xe8,
0x02,0x89,0x0b,0xe2,0xa8,0x00,0x01,0x9f,0xef,0xef,0x83,0xfe,0xef,0xfa,0xea,0xe7,
0x95,0x81,0x08,0x01,0x9a,0x9e,0x71,0x9f,0xff,0x88,0xef,0xee,0xa0,0xfb,0x03,0x4b,
0x5a,0x80,0x83,0xff,0xc0,0xfe,0xff,0xb8,0x7b,0xbe,0xef,0xf5,0x55,0xe8,0xe1,0x81,
0xdd,0xb6,0x2a,0xaa,0xbd,0x7c,0x00,0x7b,0x9e,0x08,0xf9,0x6e,0x07,0xea,0xff,0x4d,
0x38,0xfe,0xea,0x3d,0xb8,0xfa,0xfa,0xc1,0xbb,0x08,0x10,0xff,0xb0,0xa3,0x74,0x34,
0x50,0x81,0x53,0x2d,0x00,0x6e,0x09,0x09,0x88,0xf8,0xae,0xba,0xff,0xff,0xf7,0x9c,
0x5d,0xdf,0xfd,0x5d,0x55,0xe5,0xdd,0x00,0xaf,0x96,0x04,0x89,0x9d,0xd1,0xfd,0xc0,
0x51,0xae,0x01,0x04,0xf1,0x4e,0xfd,0xd5,0x55,0x55,0x57,0x75,0xd2,0xfc,0x7f,0x81,
0xff,0xf8,0xad,0x38,0x82,0x01,0x90,0x41,0x81,0x81,0xf9,0x05,0xd5,0xf6,0xfd,0x9d,
0xd5,0x75,0xff,0x55,0xc1,0xd9,0x32,0x55,0x7e,0xd0,0x54,0x95,0x55,0x74,0x68,0x23,
0xaf,0x90,0x99,0xbe,0xd9,0x5f,0xc0,0x99,0x45,0x6a,0x01,0x19,0x21,0xff,0xff,0xe7,
0xd5,0xc0,0xa8,0x14,0xf9,0x01,0x01,0xf5,0x81,0x62,0x00,0x77,0x07,0xff,0x75,0x55,
0x7d,0xa2,0x5f,0xff,0xf5,0x27,0x03,0xff,0xf6,0x60,0x63,0xd8,0xdb,0xf5,0x40,0xa0,
0xfe,0xfb,0xc0,0x03,0xb9,0x09,0xef,0x0b,0x1e,0xdb,0xd5,0xf1,0x15,0x57,0x65,0x80,
0x05,0x40,0x02,0x14,0x44,0x43,0xb9,0x12,0x40,0x04,0x40,0x00,0x01,0x00,0x06,0x08,
0x00,0x01,0xae,0xf7,0x5d,0xa7,0xdc,0x5d,0xd5,0xf5,0xf6,0xb7,0xc1,0x82,0x23,0x70,
0x78,0x67,0x72,0x25,0x7d,0xb6,0x08,0x04,0x0f,0xd5,0xfe,0x35,0xaf,0x84,0xd6,0x41,
0x76,0x5f,0x57,0xe4,0xe8,0xda,0x00,0xaa,0x40,0x04,0x82,0x40,0x4f,0x57,0x11,0x03,
0x55,0xe0,0x55,0xcb,0x58,0x01,0x26,0xce,0x3a,0xef,0xff,0x97,0x82,0x5c,0xc7,0xe0,
0x80,0x72,0x0f,0xf3,0xe7,0x6f,0x80,0x69,0x80,0x10,0xa2,0x7e,0x93,0xbf,0xea,0xb6,
0xbf,0xfb,0xb2,0x68,0x00,0x2a,0xfe,0xc0,0x01,0x2a,0x20,0xa5,0x80,0xd7,0x00,0xa9,
0x88,0x21,0xbf,0x7f,0xba,0xaa,0xb2,0xfe,0x82,0xff,0xbf,0x7d,0x2a,0x86,0xaa,0x80,
0x01,0x08,0x80,0x2a,0x83,0xa8,0x01,0x21,0xa8,0xf3,0x89,0xae,0xff,0x98,0xbf,0xbb,
0xbf,0x88,0x1a,0xcb,0xa4,0xff,0xfb,0x82,0x60,0x00,0xa0,0x08,0x00,0x08,0x18,0x20,
0xac,0x0f,0xfb,0x6b,0x0a,0xc0,0x97,0x0f,0xfe,0xfa,0xfb,0x3f,0xbd,0xff,0x5a,0x2e,
0xee,0x08,0x37,0x03,0xc1,0x7b,0xa0,0x02,0x0f,0x07,0xf7,0x49,0x4b,0xd2,0xfe,0xeb,
0xf6,0x01,0xb6,0xe8,0x44,0x9a,0x32,0xaa,0xa8,0xda,0xf0,0xbd,0x0a,0xd7,0x40,0x82,
0x02,0x02,0x1f,0xfc,0xd6,0x01,0xa6,0xed,0xae,0xff,0xf2,0x58,0x20,0x08,0xa8,0xea,
0x68,0xa1,0x00,0x86,0x1f,0xaa,0xf8,0x3f,0xff,0x4e,0x3f,0x3f,0x68,0x80,0x94,0x76,
0x89,0x81,0x66,0x01,0xe0,0x20,0xa0,0x9f,0xcd,0x07,0xaa,0xc0,0xba,0xc3,0x65,0x41,
0xb1,0xd6,0x5d,0xf7,0xf5,0x77,0xfd,0x7f,0x92,0x00,0x69,0x10,0x00,0xbf,0x99,0xdf,
0xc6,0xb4,0x3b,0x05,0x5f,0x77,0xff,0xdd,0x95,0xf9,0xf7,0x5a,0x00,0x5a,0x01,0x57,
0x70,0x02,0x55,0x4d,0x80,0x20,0x00,0x40,0x6a,0x10,0x66,0x55,0xf7,0x7d,0x26,0xdc,
0x57,0xa0,0x02,0xa2,0xff,0x96,0xd3,0x55,0x40,0x44,0x62,0x04,0x83,0x28,0xb0,0x8a,
0x01,0xc7,0x26,0x57,0x7d,0x26,0x5d,0xff,0x33,0x0d,0x0f,0x30,0x9f,0xd4,0xc0,0x50,
0xc5,0xf5,0x38,0xa0,0x00,0xa8,0x5b,0x1f,0x55,0x77,0x3d,0xd2,0x03,0x62,0x51,0x54,
0xa0,0x1c,0x7f,0x75,0xd9,0x7f,0xf5,0x7a,0x59,0x7d,0x01,0x2d,0x63,0x7b,0x00,0x1f,
0xb5,0xa0,0xd6,0x83,0x00,0xa3,0x55,0xee,0x81,0xdd,0xa1,0x21,0x3b,0x7f,0xfe,0x00,
0xae,0x84,0x06,0x7a,0x8d,0x3f,0xd0,0x69,0x00,0x81,0xd7,0x55,0x57,0x82,0x04,0x03,
0xc1,0x6c,0x5a,0x05,0xe7,0x63,0x54,0xf0,0x07,0xd2,0xc1,0x3c,0x87,0x7f,0xe0,0x70,
0xc0,0x1c,0xbf,0x16,0xfe,0xd2,0xdd,0x0b,0xd6,0xe0,0x01,0x28,0x01,0x37,0x66,0x0d,
0x53,0x00,0x75,0x99,0x02,0xef,0x3e,0xff,0xea,0xaa,0xaf,0xb0,0x81,0x77,0x0c,0xc9,
0x84,0xca,0x90,0xd6,0x05,0x41,0xd6,0x81,0x01,0x58,0xaf,0xfe,0xff,0xbe,0xca,0xb4,
0xaa,0x25,0xa8,0x02,0x6b,0xb8,0x04,0xaa,0x96,0xd0,0x00,0x29,0x10,0x2c,0x9f,0xd5,
0x47,0xa2,0x40,0xbb,0xbd,0x7d,0x59,0xab,0x43,0xea,0xaa,0x3d,0x55,0xaf,0x58,0x01,
0x86,0x51,0x0a,0x2b,0x01,0xbf,0xef,0xb0,0x80,0xac,0x32,0xb4,0xb5,0x80,0x3a,0x59,
0x52,0x37,0xaa,0xe0,0xc4,0xd5,0x89,0x00,0x61,0x28,0x73,0x0f,0xff,0xba,0xae,0xbf,
0xf6,0x81,0x01,0x6a,0xff,0xee,0xd8,0xad,0x35,0x61,0x73,0xaa,0xa0,0x04,0x01,0x83,
0x08,0x98,0x0f,0x3f,0xfc,0xfe,0xfe,0x59,0x56,0x00,0xd7,0x00,0xa8,0x20,0x87,0x01,
0x8a,0xd6,0x8b,0x40,0x6d,0x08,0x8f,0x51,0x2d,0xfc,0x99,0x58,0x01,0x96,0xef,0xfa,
0x19,0x02,0x8e,0x94,0x60,0x08,0x28,0x16,0x82,0xff,0xa8,0xe0,0x0b,0x22,0xff,0xba,
0x86,0xbb,0x03,0xc0,0x01,0x9b,0xa7,0x08,0x74,0xcd,0x9d,0xdd,0xcb,0xe7,0xa0,0x58,
0x01,0xa1,0x02,0xb7,0x99,0x1b,0xef,0x08,0xef,0xfa,0xd5,0xe3,0x1d,0xd1,0xa3,0x41,
0x55,0xe7,0x7e,0x05,0xdf,0x08,0x26,0xb4,0x75,0xc5,0xdc,0xfc,0x88,0x40,0xa9,0x04,
0x5d,0xff,0x8b,0x7f,0xe5,0x69,0x00,0x25,0x55,0x5c,0x05,0x54,0x51,0x50,0xd5,0x99,
0x00,0x82,0x45,0x55,0x77,0x87,0x18,0x43,0xa9,0x5d,0xef,0x6c,0x00,0x9d,0x7c,0x6c,
0x80,0xf5,0x2d,0x23,0xaa,0x00,0x9b,0xda,0x57,0x01,0xf5,0x6b,0x9f,0xb8,0x67,0xdf,
0xc0,0xaf,0x57,0x7f,0x56,0x01,0x6a,0x10,0xee,0x1f,0xdd,0xa6,0x5d,0x62,0x55,0x55,
0x74,0x1a,0x01,0xbf,0x95,0x58,0xdd,0x62,0xfd,0xe0,0x41,0x27,0x00,0x02,0x8d,0x9d,
0x7f,0xfc,0x4a,0xff,0x6b,0xb5,0xdd,0x9d,0x40,0xa1,0x42,0x87,0x90,0x44,0x01,0xff,
0xe0,0x57,0x00,0xd9,0xf3,0xf5,0x60,0x7d,0xde,0x5b,0xa0,0x01,0xb5,0x20,0x92,0x01,
0x79,0x01,0x00,0x02,0x54,0x06,0x09,0xc1,0xff,0x55,0xc0,0x7f,0x6b,0x95,0x4d,0xf3,
0xb5,0xe0,0x62,0x00,0x59,0x0c,0x00,0xff,0xff,0xf1,0xf0,0x40,0xa9,0xef,0x22,0x33,
0x9f,0x01,0xad,0x65,0xd5,0xd6,0xfb,0xc1,0x2a,0xab,0xbf,0xb5,0xfa,0x8e,0x18,0x8e,
0x2c,0x20,0x32,0xe7,0xef,0x0e,0xc1,0xf8,0x17,0x40,0x82,0x10,0xa3,0xaf,0xbf,0x9a,
0xbe,0xaa,0xb6,0x8a,0xeb,0x02,0x22,0xee,0x1a,0x29,0xa8,0xfb,0x97,0xb7,0x10,0x56,
0x40,0x26,0x90,0xaa,0xbe,0x3b,0xc1,0xaa,0x5e,0x00,0x29,0x00,0x39,0x9f,0xfa,0xae,
0xb2,0xff,0xc5,0xa7,0xbe,0x80,0xc0,0x69,0x7f,0xbb,0xab,0xda,0xbd,0xd2,0xb7,0x01,
0xf2,0x28,0x06,0xad,0xfb,0x31,0xe5,0x6b,0x6c,0xb7,0xd7,0xfb,0x00,0x9a,0x21,0x9c,
0x3f,0x66,0xaf,0xaa,0xaf,0x66,0xbf,0xfa,0xb4,0x4d,0x1b,0xaa,0x89,0xad,0xb3,0xfc,
0x62,0x41,0x2a,0x20,0x1b,0xa0,0xb1,0x31,0xb0,0x6a,0x41,0xbd,0xa8,0xfa,0xf2,0x28,
0x00,0xaf,0x52,0x65,0xbe,0x42,0xeb,0xc0,0x32,0xe8,0xba,0xe1,0x05,0xfb,0xdd,0x85,
0x73,0x00,0x8d,0xd1,0x0b,0x22,0x36,0x11,0x01,0xa6,0xe0,0x4b,0x00,0x2e,0xab,0xe3,
0x2f,0x5f,0x02,0x1b,0x46,0xda,0x6f,0x01,0x00,0x6a,0x02,0x0a,0x68,0x03,0xfe,0x1f,
0x98,0xe0,0x02,0x09,0xf7,0x08,0x6b,0xff,0x2b,0xbb,0xb7,0xba,0xfd,0x77,0xf5,0x9d,
0xa5,0x5f,0xff,0xa6,0x75,0x0c,0x14,0x40,0x42,0x45,0x3d,0xb4,0x69,0x3a,0xd7,0x1d,
0x81,0xd7,0x00,0x9a,0x00,0x05,0x57,0x22,0x7f,0x9b,0x26,0x67,0xd5,0xa4,0x00,0x86,
0x77,0x14,0x15,0x55,0x54,0x01,0x22,0x00,0x20,0x88,0x01,0x22,0x01,0x57,0x5d,0x7d,
0x21,0x35,0x05,0xa8,0x03,0xaa,0xff,0x57,0x57,0xa9,0x02,0x10,0x71,0xd5,0x01,0xac,
0xc2,0xbd,0x59,0x40,0xef,0x81,0x1c,0xf3,0xad,0xfe,0xd5,0x66,0x01,0x17,0x40,0x01,
0x19,0xaa,0x00,0x79,0xff,0xd5,0x8f,0x5f,0xd0,0xc4,0xa4,0x80,0x92,0x05,0xb1,0x44,
0x11,0xe7,0xfe,0x8e,0x07,0x84,0xb1,0x71,0x6a,0x41,0x74,0x93,0x7d,0x8b,0xd2,0x0e,
0x47,0xb1,0x59,0x00,0xa2,0x02,0xa6,0x03,0x41,0x91,0xbf,0xa9,0xfd,0x86,0x55,0xd5,
0xf7,0xed,0x1a,0xcb,0x05,0x6a,0x3f,0x04,0x31,0xc2,0x30,0xe4,0x00,0x9b,0x11,0xc4,
0xf7,0x5f,0x55,0xfd,0xdd,0x4c,0xf3,0x58,0x0c,0xfd,0x1a,0x49,0x81,0xdf,0xfc,0x07,
0xdc,0x80,0x56,0xcf,0x5b,0x11,0xc7,0x7f,0x1f,0x67,0x60,0xd7,0x0a,0x7e,0xd7,0xba,
0x58,0xf9,0xb6,0x7e,0x0c,0xe0,0x0f,0xf8,0x87,0xee,0xfb,0x00,0x68,0xf7,0x29,0xff,
0x2d,0xaa,0xde,0xa0,0xfa,0x6d,0x9c,0x77,0x45,0x1e,0xe8,0x92,0x68,0x01,0xba,0x37,
0xf6,0xaa,0x6a,0xaa,0xbf,0xef,0x00,0x4f,0x39,0x87,0xcc,0xee,0xec,0xb5,0xfe,0x57,
0x5a,0xbf,0xee,0xf9,0xd9,0x92,0xc1,0x38,0x80,0x09,0xa0,0xb7,0xf2,0xad,0xab,0x4a,
0xf8,0xa4,0x6f,0xfe,0x30,0x07,0xbe,0xee,0xfc,0x7e,0xcd,0xbe,0xee,0xaf,0x72,0x79,
0xa1,0xa0,0xf5,0x48,0x06,0x1b,0xfd,0xaa,0x7f,0x6e,0x64,0x47,0x4a,0x30,0x04,0x10,
0x02,0x47,0x35,0xd6,0x2f,0xba,0x39,0x7d,0xa1,0xea,0xea,0xfe,0x19,0x01,0x20,0x00,
0x9f,0xff,0x4a,0xaa,0xa9,0xfb,0xfa,0x9f,0x7f,0x00,0x30,0x24,0x10,0xad,0xeb,0x7d,
0x82,0xab,0xe2,0x77,0xf0,0x1f,0x65,0xf4,0xc0,0x0b,0xc2,0x00,0xa3,0xfe,0xfa,0xc1,
0xd5,0x99,0xfc,0x13,0xc1,0xdd,0xa3,0x72,0xfe,0x4c,0x13,0x4b,0xf5,0x3c,0x22,0x4c,
0xa3,0xbd,0x20,0xa3,0xeb,0x6f,0x3f,0xef,0x20,0x77,0x8b,0x40,0x20,0x82,0x14,0x25,
0x1d,0xdf,0xf9,0xcd,0xcb,0xfc,0x81,0x8b,0xfd,0xfc,0x88,0x04,0xaa,0xff,0x0a,0xfa,
0xab,0xaf,0x3c,0x81,0x29,0x9c,0xab,0x8c,0xb6,0xee,0xa9,0xc1,0xf6,0x83,0x6b,0xd5,
0x78,0x42,0x3d,0x5b,0x51,0x40,0x1b,0xf8,0x03,0xf5,0x3c,0x2a,0x80,0x77,0xd8,0x1b,
0xb5,0x75,0x1d,0xd7,0xcb,0xba,0xd0,0xd9,0x7d,0x00,0x8a,0x00,0xd1,0x29,0xf0,0x01,
0xb4,0x55,0x1d,0xab,0x93,0x93,0x29,0x57,0x51,0xf7,0xdc,0xbe,0xeb,0xc0,0xdf,0x22,
0x37,0x55,0x57,0xe8,0x7c,0x35,0x09,0x30,0x17,0xf3,0xed,0xf9,0xa0,0xd8,0x01,0xeb,
0x7e,0x46,0xd5,0xdf,0xe4,0x75,0xc0,0xd7,0xf7,0x81,0x5b,0x0d,0x9f,0xd6,0xb7,0x8d,
0xa2,0x48,0x0b,0xfd,0xe8,0x7e,0xcd,0x54,0xec,0xa3,0xa1,0x00,0x82,0x00,0x77,0x7b,
0xd5,0x37,0x29,0xdd,0x55,0x5a,0x5d,0x5d,0xff,0x40,0x03,0x60,0x41,0x0f,0x9f,0x40,
0x00,0x04,0x77,0xf5,0x4f,0xaa,0x40,0x44,0x18,0x77,0xc5,0x7f,0x15,0xd7,0x3b,0xf7,
0x0f,0x8d,0x59,0x51,0xfe,0x1d,0x73,0x22,0x8b,0xde,0xf0,0x27,0x47,0x55,0xfc,0x9f,
0x41,0x30,0xcd,0x58,0x6b,0x8e,0xfd,0x85,0x54,0x02,0x8d,0xdf,0x7f,0xa6,0xb8,0xd7,
0x57,0x3d,0x2a,0x01,0xe8,0xc8,0xc1,0x4f,0xa3,0x01,0x12,0x9e,0xb6,0x1a,0x89,0x76,
0x44,0x54,0x5d,0x00,0x69,0xdd,0xc2,0x98,0xe1,0x5d,0xf4,0x04,0x42,0xe5,0x53,0x77,
0xb7,0xe7,0xb6,0xdc,0xfd,0xd5,0x55,0xa1,0xdc,0x9a,0xaa,0xcf,0x7f,0xf8,0x80,0x60,
0xc1,0xb2,0x97,0x3b,0xc4,0xbd,0xcf,0x33,0x6a,0x01,0xff,0x49,0xfa,0x09,0xee,0xef,
0x00,0xef,0xa9,0xfb,0x86,0xba,0xaa,0xbe,0x62,0x1a,0x30,0xb7,0xa0,0xbf,0xa0,0xae,
0xfb,0x80,0x57,0xa2,0x29,0xae,0xab,0xde,0xb6,0xfa,0x3a,0x43,0xba,0x6d,0xfa,0x1e,
0xd0,0x4d,0x12,0x50,0xb7,0xfb,0x2a,0xb3,0x68,0x00,0x89,0xe0,0x6d,0x2f,0x24,0x3e,
0xce,0xc0,0x3a,0xfe,0xbe,0x8a,0xbf,0xeb,0x63,0x3f,0xfe,0xfc,0x63,0x9d,0x2b,0xfe,
0x58,0x01,0x2a,0xbf,0x6a,0xaa,0xea,0x20,0x0b,0x57,0x5c,0xaf,0xfe,0xcd,0xfe,0x73,
0x2b,0xaf,0xee,0x80,0x60,0x01,0x6a,0x02,0x27,0x7f,0x2a,0xaa,0xa2,0x1f,0xf6,0xef,
0x02,0xa9,0xa4,0xd3,0xbe,0x2b,0x7d,0xab,0x48,0x7a,0xde,0xf4,0x07,0xea,0xf8,0x07,
0xc0,0x42,0x2b,0xee,0x7a,0xaa,0xd6,0xd9,0x00,0x20,0xa6,0x7a,0xc0,0x04,0x41,0xbe,
0xae,0xae,0x0a,0xbf,0x20,0xa2,0xfe,0xff,0xab,0x3e,0x02,0xaa,0xa0,0xd2,0x92,0xee,
0x02,0x00,0x30,0x08,0x21,0x92,0x3f,0xb7,0xfe,0xa6,0x2a,0xbb,0x02,0xa2,0xfb,0x90,
0x12,0x25,0xb7,0xca,0xaa,0xaa,0xea,0xae,0xb5,0xc0,0x00,0x8c,0x2c,0xb6,0xaa,0x06,
0xfd,0x70,0x19,0x15,0xdc,0x66,0x0c,0xad,0x46,0x53,0x67,0x41,0xf5,0x61,0x78,0x18,
0x00,0x83,0xf5,0x07,0x58,0xfd,0x58,0x00,0xa2,0xfd,0x22,0x55,0x57,0x28,0xc0,0x80,
0x88,0x06,0x31,0xa0,0x00,0x1f,0xa5,0x43,0x61,0x80,0xef,0x98,0x31,0x9d,0x5e,0xd7,
0x5c,0xbd,0xd7,0x98,0xff,0x57,0xaa,0x55,0xf0,0x00,0x26,0x13,0x60,0x86,0x12,0xd8,
0x04,0x41,0xd2,0x1c,0xc2,0x75,0xb4,0xa5,0xf5,0xfe,0x2d,0xf7,0xfe,0x72,0x17,0xbe,
0xd5,0xae,0x1d,0x2f,0xf5,0x1d,0x1f,0x5f,0x85,0xd4,0x7f,0x62,0x00,0x0b,0x6d,0x5f,
0xd7,0x4f,0x9d,0x7c,0x4d,0x49,0xad,0x01,0x02,0x62,0x41,0x7b,0x84,0x62,0xb1,0x67,
0x75,0x93,0x01,0xf8,0x41,0x77,0x51,0x97,0x3d,0x27,0xbc,0x59,0x41,0x28,0x75,0xe0,
0x07,0x80,0x40,0x07,0xa8,0x70,0x10,0x17,0xe8,0x80,0xdc,0x76,0x40,0x01,0x67,0xb7,
0x45,0x45,0x5f,0x1a,0xc4,0x0e,0xf5,0x77,0x75,0x57,0xf9,0xf5,0x7e,0xcb,0xa8,0x01,
0x21,0x8a,0x41,0x5f,0x04,0x22,0x00,0x10,0x8a,0xfe,0xfd,0x60,0x55,0x15,0x1f,0x9a,
0x7f,0xfd,0x7f,0xa9,0xc3,0x10,0x96,0x49,0x51,0x03,0xd5,0x5c,0xf5,0xc0,0xa9,0x20,
0x9f,0x01,0x04,0x24,0xff,0x2b,0xde,0xf8,0x5b,0x02,0x6a,0x80,0x24,0x93,0xbf,0xf2,
0xa9,0xfa,0xba,0x8f,0x5a,0x00,0xa6,0x7f,0xf8,0x2f,0xb3,0x29,0xfe,0xaa,0xff,0xae,
0x82,0xbb,0xf9,0xfe,0x38,0x22,0x06,0x60,0x6a,0xaf,0x2a,0xea,0xab,0xdf,0x82,0x28,
0x2a,0xbe,0xee,0x5a,0xfe,0x86,0x1f,0xbe,0xfe,0xff,0xea,0x26,0x16,0x20,0x9f,0x22,
0x9b,0xea,0x66,0x6f,0x00,0x20,0x82,0x1a,0x82,0x00,0x3d,0x48,0x2a,0xfe,0xee,0xfc,
0xff,0xf0,0x2a,0x90,0x98,0x0f,0x2a,0x9f,0xaf,0xea,0xb2,0x82,0x66,0x00,0x6f,0xbf,
0xaf,0x6f,0xfe,0x3d,0x7d,0x60,0x85,0xd6,0xc0,0xc4,0xaf,0xfb,0xc0,0xd2,0xe9,0x75,
0xaf,0x7f,0x0a,0xa5,0x00,0xbc,0xf4,0xa3,0x7f,0xb2,0x58,0x9f,0xef,0xba,0x9b,0xf0,
0x4f,0x80,0x58,0x67,0xda,0x32,0x6a,0xfc,0xda,0xec,0x00,0x2b,0xfc,0x60,0x01,0x75,
0xdb,0x64,0x40,0x8c,0xba,0x7c,0x34,0x41,0xb5,0x5f,0x8a,0x69,0x01,0xdf,0xf6,0x01,
0x65,0x35,0x00,0xdd,0xbe,0x41,0x26,0xc0,0xaa,0xef,0x3f,0xa5,0xfe,0xad,0xc7,0xf8,
0x80,0x48,0x95,0xbf,0x2a,0xab,0xb5,0x81,0xbf,0xa9,0x01,0x00,0x93,0x0b,0xc6,0xee,
0x5e,0x86,0xb5,0x06,0xa2,0x80,0x14,0x71,0xf8,0xed,0xe1,0xd7,0xf7,0xc0,0x00,0x82,
0xc0,0x1f,0x46,0xdc,0x18,0x88,0xf5,0xd5,0x68,0x54,0xfc,0x05,0x80,0x00,0xaa,0x04,
0x20,0xf2,0xf5,0x4f,0xe7,0x60,0x41,0x27,0xed,0xf7,0x38,0x54,0x77,0xd6,0xdc,0xba,
0x98,0xbd,0x55,0xfe,0x1f,0xee,0xf3,0xfc,0x1c,0x87,0x1b,0x09,0x40,0x49,0x65,0xb5,
0x60,0xed,0x00,0x10,0x88,0x01,0x75,0xd5,0x66,0xf5,0x55,0xf9,0xf5,0xd9,0xa6,0x00,
0x40,0x47,0xf7,0x26,0x0f,0x59,0x65,0x1a,0x14,0x82,0xdd,0x7d,0x55,0xb7,0x0b,0xd5,
0xda,0x85,0xf9,0xf8,0x21,0xd6,0xc0,0x44,0x47,0xbb,0xc4,0x01,0x20,0x17,0xd5,0x9a,
0xc4,0x00,0xf1,0x0a,0x76,0xe3,0x05,0x4e,0x8a,0x55,0xdf,0x66,0x55,0xff,0x9f,0x86,
0x10,0x39,0xfd,0xb4,0x40,0xa2,0x57,0xfd,0xdf,0x41,0xf1,0x76,0x7d,0xc1,0x77,0x45,
0x55,0x1f,0x78,0x92,0x5d,0xf5,0xd5,0xff,0x56,0x7c,0xc5,0xb5,0x40,0x4d,0xbb,0x6b,
0x01,0x57,0xea,0xc9,0x41,0x60,0x0e,0xe5,0xbd,0xfd,0x54,0xc1,0xda,0x7f,0x00,0x66,
0x9f,0xdd,0x7f,0x12,0xa0,0x00,0x41,0x3f,0x90,0xc0,0x05,0xf5,0x55,0x6d,0x2a,0x3f,
0x0d,0xc1,0x87,0x54,0xbd,0x7a,0x00,0xef,0x8a,0xaa,0xc0,0x2a,0x01,0xc3,0x80,0x9a,
0x0a,0xba,0xb7,0x49,0xaa,0xfb,0xaf,0x9b,0xf4,0x01,0x82,0xe2,0xff,0xaf,0xec,0x4b,
0xbf,0x5b,0x5c,0xe6,0x5d,0xc1,0xff,0x04,0xb2,0x75,0xa9,0x01,0xaa,0xa9,0xc0,0x6f,
0xf7,0x3a,0x88,0xbd,0xfe,0x6a,0xfc,0x29,0xef,0xbe,0x29,0xff,0xf8,0x01,0x24,0x04,
0x1b,0x82,0x8a,0x24,0xfa,0x8a,0x88,0x10,0x2a,0x32,0x82,0xef,0x6a,0xbf,0xba,0xf3,
0xfa,0x22,0x01,0xb0,0xa6,0x6f,0x68,0xa7,0x6f,0xfa,0x98,0xbf,0x00,0x60,0x02,0x7d,
0x7e,0xff,0x57,0xa6,0xfb,0x29,0xfe,0xf8,0x28,0x05,0xc2,0x02,0x2b,0xcf,0xea,0x26,
0xab,0xbf,0x2a,0xab,0xc3,0x86,0x1d,0x67,0xa5,0xa7,0xae,0xe7,0x57,0x48,0xb4,0x3f,
0x99,0x34,0x3d,0x80,0x30,0x13,0xff,0xa2,0x8a,0x7f,0x9c,0xe5,0xef,0x08,0x20,0x0b,
0xee,0x5a,0x01,0xfe,0x06,0x5a,0xfe,0xbf,0xea,0xfc,0x88,0x02,0xa2,0x1a,0x22,0x8a,
0xab,0xbf,0x2b,0x88,0x20,0xa8,0x02,0x20,0x8d,0x23,0xbb,0xef,0x4f,0xfc,0xad,0xbe,
0x2f,0xb8,0x01,0xa2,0xa5,0xd6,0xda,0x8a,0x01,0x22,0xbe,0xef,0x18,0x7f,0x8e,0x21,
0x07,0x6e,0x22,0xff,0x75,0x30,0x3b,0xc4,0x04,0x59,0x01,0x98,0x04,0xbd,0x37,0x49,
0x40,0xe9,0xfa,0x04,0x40,0x77,0x21,0x81,0x7f,0x36,0x33,0x09,0xd7,0xbd,0x84,0xd1,
0x31,0x93,0x6a,0x40,0xf6,0x88,0x27,0x55,0x2d,0x5f,0xb5,0xeb,0x56,0xa4,0x01,0xb5,
0x8a,0xff,0xbf,0x8a,0x75,0xe0,0xa8,0x28,0x6a,0x1f,0xf9,0x81,0x02,0xf5,0x54,0x29,
0x10,0xa6,0x00,0x82,0x77,0xa8,0xd5,0xe3,0xa8,0xf8,0xa6,0x01,0x30,0x37,0xfe,0x40,
0x86,0x03,0xb7,0xf5,0xd1,0x6f,0x6a,0x10,0x2a,0x73,0x77,0x27,0x18,0x8a,0x57,0x9f,
0xfc,0x92,0x01,0xc6,0x00,0x07,0xfd,0xf0,0x62,0x15,0x57,0x6a,0x04,0x28,0x00,0x01,
0x22,0x59,0x45,0x32,0xdf,0x2a,0xfd,0x7f,0xf5,0x19,0x26,0x70,0x05,0xff,0xa1,0x00,
0x10,0x22,0x7d,0x10,0x22,0x04,0x60,0xa8,0xd7,0x51,0xa8,0x7f,0xa0,0x57,0xd5,0xa5,
0x57,0xbf,0x54,0xfc,0xa9,0x00,0x03,0x7e,0x30,0x1c,0x11,0x3f,0x7e,0xe9,0x82,0xd6,
0x1f,0x7d,0xf5,0x01,0x12,0x1b,0xfd,0xdf,0xf5,0x7b,0xf7,0x7f,0xdf,0x0d,0x0f,0xa8,
0xc1,0x22,0x00,0x1f,0xef,0x00,0x98,0x5d,0x63,0x75,0x8c,0x40,0x07,0x64,0x55,0x55,
0x80
};


static const unsigned char attrs[] = {
0x81,0x78,0x99,0x7e,0x7f,0x7e,0xff,0xf3,0xf6,0x82,0xfe,0x39,0x72,0x68,0xc0,0xa7,                                                                                                                                   
0x50,0xde,0xb0,0xc1,0x24,0x7f,0x7f,0xa0,0x70,0x29,0x50,0xf8,0xd9,0xbe,0x7f,0x78,                                                                                                                                   
0xfe,0xc0,0xbf,0xc0,0x1a,0x7e,0x28,0x40,0x1e,0x82,0x78,0xf3,0xf3,0x48,0x68,0x3e,                                                                                                                                   
0x85,0x80,0xe3,0x84,0xf3,0xf9,0xba,0x77,0xd2,0x73,0xb4,0xff,0xc7,0xca,0x5b,0x83,                                                                                                                                   
0xc0,0x6f,0x82,0x70,0x7c,0x00,0xa7,0x48,0xf8,0xc0,0x90,0x38,0x2a,0x3f,0xa8,0xde,                                                                                                                                   
0xc3,0xd7,0x3f,0x60,0x40,0x40,0x68,0x72,0xe8,0x62,0x48,0x48,0x77,0xcb,0x7d,0x98,                                                                                                                                   
0xf8,0xfd,0xc1,0xbe,0xf2,0xd9,0xbe,0x3d,0xbe,0xff,0x4f,0x80,0xff,0xda,0xc0,0xf9,                                                                                                                                   
0xc6,0xbe,0xe4,0xc0,0x89,0x72,0x70,0xa2,0x70,0x83,0x78,0x8f,0xbc,0x06,0x78,0xa6,                                                                                                                                   
0xef,0xc0,0x43,0xfe,0x74,0xc1,0x7c,0x7f,0xba,0xe9,0xbe,0x68,0x3b,0xc0,0x77,0x9c,                                                                                                                                   
0xdf,0xe5,0xfd,0xda,0xb9,0x68,0x7e,0x36,0xbe,0xec,0x86,0xff,0xf6,0xe4,0xfa,0xfe,                                                                                                                                   
0xc0,0x85,0x48,0xdb,0x0c,0x23,0xb4,0x8f,0x5a,0xfe,0xf7,0x40,0x76,0xbe,0xc8,0x72,                                                                                                                                   
0x40,0xdd,0xc1,0x55,0x56                                                                                                                                                                                           
};

__at (SCREEN_BUFFER_START) char screen_buf[0x1800];
__at (ATTR_SCREEN_BUFFER_START) char screen_attr_buf[0x300];

void unpack(char *src, char *dst);
void unpack_naked();

void main() {
  unpack(image, screen_buf);
  unpack(attrs, screen_attr_buf);
  for (;;);
}

void unpack(char *src, char *dst) {
(void) src, dst;

  __asm
  ld ix, #4                                                                                                                                                                                                        
  add ix, sp                                                                                                                                                                                                       

  ld l, 0(ix)                                                                                                                                                                                                      
  ld h, 1(ix)
  ld e, 2(ix)
  ld d, 3(ix)
  call #_unpack_naked
  __endasm;  
  }

/*; -----------------------------------------------------------------------------
; ZX0 decoder by Einar Saukas & Urusergi
; "Standard" version (68 bytes only)
; https://github.com/einar-saukas/ZX0
; -----------------------------------------------------------------------------
; Parameters:
;   HL: source address (compressed data)
;   DE: destination address (decompressing)
; ----------------------------------------------------------------------------- */
void unpack_naked() {
  __asm
dzx0_standard:
        ld      bc, #0xffff               ; preserve default offset 1
        push    bc
        inc     bc
        ld      a, #0x80
dzx0s_literals:
        call    dzx0s_elias             ; obtain length
        ldir                            ; copy literals
        add     a, a                    ; copy from last offset or new offset?
        jr      c, dzx0s_new_offset
        call    dzx0s_elias             ; obtain length
dzx0s_copy:
        ex      (sp), hl                ; preserve source, restore offset
        push    hl                      ; preserve offset
        add     hl, de                  ; calculate destination - offset
        ldir                            ; copy from offset
        pop     hl                      ; restore offset
        ex      (sp), hl                ; preserve offset, restore source
        add     a, a                    ; copy from literals or new offset?
        jr      nc, dzx0s_literals
dzx0s_new_offset:
        pop     bc                      ; discard last offset
        ld      c, #0xfe                  ; prepare negative offset
        call    dzx0s_elias_loop        ; obtain offset MSB
        inc     c
        ret     z                       ; check end marker
        ld      b, c
        ld      c, (hl)                 ; obtain offset LSB
        inc     hl
        rr      b                       ; last offset bit becomes first length bit
        rr      c
        push    bc                      ; preserve new offset
        ld      bc, #1                   ; obtain length
        call    nc, dzx0s_elias_backtrack
        inc     bc
        jr      dzx0s_copy
dzx0s_elias:
        inc     c                       ; interlaced Elias gamma coding
dzx0s_elias_loop:
        add     a, a
        jr      nz, dzx0s_elias_skip
        ld      a, (hl)                 ; load another group of 8 bits
        inc     hl
        rla
dzx0s_elias_skip:
        ret     c
dzx0s_elias_backtrack:
        add     a, a
        rl      c
        rl      b
        jr      dzx0s_elias_loop
__endasm;
}