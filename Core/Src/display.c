#include "display.h"

displaying_number actual_number = {0};
uint64_t actual_time = 0;
uint64_t last_refresh = 0;

void SegmentsOFF()
{
	SEGMENT_A_OFF;
	SEGMENT_B_OFF;
	SEGMENT_C_OFF;
	SEGMENT_D_OFF;
	SEGMENT_E_OFF;
	SEGMENT_F_OFF;
	SEGMENT_G_OFF;
	SEGMENT_DT_OFF;
}

void DigitsOFF()
{
	DIGIT_1_OFF;
	DIGIT_2_OFF;
	DIGIT_3_OFF;
	DIGIT_4_OFF;
}

void setOne()
{
	SEGMENT_B_ON;
	SEGMENT_C_ON;
}

void setTwo()
{
	SEGMENT_A_ON;
	SEGMENT_B_ON;
	SEGMENT_G_ON;
	SEGMENT_E_ON;
	SEGMENT_D_ON;
}

void setThree()
{
	SEGMENT_A_ON;
	SEGMENT_B_ON;
	SEGMENT_G_ON;
	SEGMENT_C_ON;
	SEGMENT_D_ON;
}

void setFour()
{
	SEGMENT_F_ON;
	SEGMENT_B_ON;
	SEGMENT_G_ON;
	SEGMENT_C_ON;
}

void setFive()
{
	SEGMENT_A_ON;
	SEGMENT_F_ON;
	SEGMENT_G_ON;
	SEGMENT_C_ON;
	SEGMENT_D_ON;
}

void setSix()
{
	SEGMENT_A_ON;
	SEGMENT_F_ON;
	SEGMENT_G_ON;
	SEGMENT_E_ON;
	SEGMENT_C_ON;
	SEGMENT_D_ON;
}

void setSeven()
{
	SEGMENT_A_ON;
	SEGMENT_B_ON;
	SEGMENT_C_ON;
}

void setEight()
{
	SEGMENT_A_ON;
	SEGMENT_B_ON;
	SEGMENT_C_ON;
	SEGMENT_D_ON;
	SEGMENT_E_ON;
	SEGMENT_F_ON;
	SEGMENT_G_ON;
}

void setNine()
{
	SEGMENT_A_ON;
	SEGMENT_B_ON;
	SEGMENT_C_ON;
	SEGMENT_D_ON;
	SEGMENT_F_ON;
	SEGMENT_G_ON;
}

void setZero()
{
	SEGMENT_A_ON;
	SEGMENT_B_ON;
	SEGMENT_C_ON;
	SEGMENT_D_ON;
	SEGMENT_E_ON;
	SEGMENT_F_ON;
}

void setNumberForDisplay(double number)
{
	if(number >= 0)
	{
		uint8_t i = 0;
		if(number > 9999)
		{
			actual_number.digit_number = 4;
			actual_number.decimal_point = 0;
		}
		else if(number >= 1000)
		{
			actual_number.digit_number = 4;
			actual_number.decimal_point = 0;

			while(number > 1)
			{
				actual_number.digit[i] = (uint32_t)number % 10;
				number = number / 10;
				i++;
			}
		}
		else if(number >= 100)
		{
			actual_number.digit_number = 3;
			actual_number.decimal_point = 1;

			number = number * 10;

			while(number > 1)
			{
				actual_number.digit[i] = (uint32_t)number % 10;
				number = number / 10;
				i++;
			}
		}
		else if(number >= 10)
		{
			actual_number.digit_number = 2;
			actual_number.decimal_point = 2;

			number = number * 100;

			while(number > 1)
			{
				actual_number.digit[i] = (uint32_t)number % 10;
				number = number / 10;
				i++;
			}
		}
		else if(number >= 1)
		{
			actual_number.digit_number = 1;
			actual_number.decimal_point = 3;

			number = number * 1000;

			while(number > 1)
			{
				actual_number.digit[i] = (uint32_t)number % 10;
				number = number / 10;
				i++;
			}
		}
		else if(number >= 0)
		{
			actual_number.digit_number = 1;
			actual_number.decimal_point = 3;

			number = number * 1000;
			actual_number.digit[3] = 0;

			while(number > 1)
			{
				actual_number.digit[i] = (uint32_t)number % 10;
				number = number / 10;
				i++;
			}
		}
	}
}

void setDigit(uint8_t digit)
{
	switch(digit)
	{
		case 0:
			DIGIT_4_ON;
			break;
		case 1:
			DIGIT_3_ON;
			break;
		case 2:
			DIGIT_2_ON;
			break;
		case 3:
			DIGIT_1_ON;
			break;
	}
}

void displayRefresh()
{
	for(int8_t i = 0; i < 4; i++)
	{
		switch(actual_number.digit[i])
		{
			case 0:
			  setDigit(i);
			  setZero();
			  break;
			case 1:
			  setDigit(i);
			  setOne();
			  break;
			case 2:
			  setDigit(i);
			  setTwo();
			  break;
			case 3:
			  setDigit(i);
			  setThree();
			  break;
			case 4:
			  setDigit(i);
			  setFour();
			  break;
			case 5:
			  setDigit(i);
			  setFive();
			  break;
			case 6:
			  setDigit(i);
			  setSix();
			  break;
			case 7:
			  setDigit(i);
			  setSeven();
			  break;
			case 8:
			  setDigit(i);
			  setEight();
			  break;
			case 9:
			  setDigit(i);
			  setNine();
			  break;
		}

		if(actual_number.decimal_point == i)
		{
			SEGMENT_DT_ON;
		}

		last_refresh = actual_time;
		while(actual_time < (last_refresh + DISPLAY_PERIOD)){};

		DigitsOFF();
		SegmentsOFF();
	}
}

void TIM2_IRQHandler(void)
{
	if(LL_TIM_IsActiveFlag_UPDATE(TIM2))
	{
		displayRefresh();
	}

	LL_TIM_ClearFlag_UPDATE(TIM2);
}

