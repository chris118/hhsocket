//
//  Utility.h
//  hhsocket_client
//
//  Created by xiaopeng on 16/9/11.
//  Copyright © 2016年 hh. All rights reserved.
//

#ifndef Utility_h
#define Utility_h

#define byte char

/**
 * 将int数值转换为占四个字节的byte数组，本方法适用于(低位在前，高位在后)的顺序。 和bytesToInt（）配套使用
 * @param value
 *            要转换的int值
 * @return byte数组
 */
byte* intToBytes( int value);
/**
 * 将int数值转换为占四个字节的byte数组，本方法适用于(高位在前，低位在后)的顺序。  和bytesToInt2（）配套使用
 */
byte* intToBytes2(int value);


/**
 * byte数组中取int数值，本方法适用于(低位在前，高位在后)的顺序，和和intToBytes（）配套使用
 *
 * @param src
 *            byte数组
 * @param offset
 *            从数组的第offset位开始
 * @return int数值
 */
int bytesToInt(byte* src, int offset);

/**
 * byte数组中取int数值，本方法适用于(低位在后，高位在前)的顺序。和intToBytes2（）配套使用
 */
int bytesToInt2(byte* src, int offset);
    
    
byte* hexStringToByte(std::string hex);

#endif /* Utility_h */
