#include <stdio.h>
#include <math.h>
#include "DebugPlotU.h"

#define BUF_SIZE  128
static int lineDataBuf[BUF_SIZE];
static COMPLEX16 dotsDataBuf[BUF_SIZE];

static void PrepareData()
{
	const int AMPLITUDE = 127;
	const int PERIOD = 32;
	const double PI_2 = 3.14;

	for (int i = 0; i < BUF_SIZE; i++)
	{
		double phase		= i * PI_2 / PERIOD;
		dotsDataBuf[i].re	= (short)(AMPLITUDE * cos(phase));
		dotsDataBuf[i].im	= (short)(AMPLITUDE * sin(phase));
		lineDataBuf[i]		= dotsDataBuf[i].re;
	}
}

int Manual1()
{
	DebugPlotInit();

	PrepareData();

	PlotLine("line graph", lineDataBuf, BUF_SIZE);
	PlotSpectrum("spectrum graph", lineDataBuf, BUF_SIZE);
	PlotDots("circular", dotsDataBuf, BUF_SIZE);
	PlotText("text", "some text");
	Log("log", "We've done plotting");
	
	getchar();

	DebugPlotDeinit();

	return 0;
}
