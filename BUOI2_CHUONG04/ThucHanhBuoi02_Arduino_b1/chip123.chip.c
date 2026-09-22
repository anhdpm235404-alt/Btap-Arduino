#include "wokwi-api.h"
#include <stdlib.h>

typedef struct {
  pin_t pin_vout;
} chip_state_t;

void chip_init(void) {
  chip_state_t *chip = malloc(sizeof(chip_state_t));
  
  // Khởi tạo chân VOUT là chân xuất tín hiệu Analog
  chip->pin_vout = pin_init("VOUT", ANALOG);
  
  // LM35 xuất ra 10mV cho mỗi độ C. Giả lập nhiệt độ 35 độ C -> 0.35V
  pin_dac_write(chip->pin_vout, 0.35); 
}