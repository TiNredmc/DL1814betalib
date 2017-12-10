/**
 * DL1414 - Library for writing data on a DL1814 Display module(modified).
 * Created By Burak Özhan, 2016-Nov-14
 * Modified to DL1814 by TinLetHax, 2017-DEC-10 21.35 +07.00 time zone Thailand 
 * Released with MIT License
 */
#ifndef DL1814_h
#define DL1814_h

#include "Arduino.h"

class DL1814 
{
	public:
		DL1814(int write, int addr0, int addr1, int addr2, int data0, int data1, int data2, int data3, int data4, int data5, int data6);
		void writeByte(char a, byte column);
		void clear();
		void writeStringFix(String text);
		void writeStringScrolling(String text, int speed);
		void writeStringScrollingNoDelay(String text, int speed, long now);
		bool updateScrollingString(long now);
	private:
		int _write;
		int _addr0;
		int _addr1;
		int _addr2;
		int _data0;
		int _data1;
		int _data2;
		int _data3;
		int _data4;
		int _data5;
		int _data6;
		long _start;
		long _speed;
		byte *_noDelayBuffer;
		int _noDelayBufferLength;
		bool _scrollingTextIsSet;
};

#endif