#include "main.h"

#define DISPLAY_PERIOD 	0 // 1/frequency

#define SEGMENT_A_ON LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_1)
#define SEGMENT_A_OFF LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_1)

#define SEGMENT_B_ON LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_0)
#define SEGMENT_B_OFF LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_0)

#define SEGMENT_C_ON LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_8)
#define SEGMENT_C_OFF LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_8)

#define SEGMENT_D_ON LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5)
#define SEGMENT_D_OFF LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5)

#define SEGMENT_E_ON LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_11)
#define SEGMENT_E_OFF LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_11)

#define SEGMENT_F_ON LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6)
#define SEGMENT_F_OFF LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_6)

#define SEGMENT_G_ON LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_4)
#define SEGMENT_G_OFF LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_4)

#define SEGMENT_DT_ON LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_1)
#define SEGMENT_DT_OFF LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_1)

#define DIGIT_1_ON		LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_5)
#define DIGIT_1_OFF		LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_5)
#define DIGIT_2_ON		LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_4)
#define DIGIT_2_OFF		LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_4)
#define DIGIT_3_ON		LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_6)
#define DIGIT_3_OFF		LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_6)
#define DIGIT_4_ON		LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_2)
#define DIGIT_4_OFF		LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_2)

typedef struct
{
	uint8_t digit[4];
	uint8_t digit_number;
	uint8_t decimal_point;
}displaying_number;

void setNumberForDisplay(double number);
void displayRefresh();
void setDigit(uint8_t digit);


void SegmentsOFF();
void DigitsOFF();
void resetSegments();
void setSegments();

void setDecimalPoint();
void setOne();
void setTwo();
void setThree();
void setFour();
void setFive();
void setSix();
void setSeven();
void setEight();
void setNine();
void setZero();

void TIM2_IRQHandlerr(void);
