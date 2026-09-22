#include "wokwi-api.h"
#include <stdlib.h>

typedef struct {
  pin_t pin_out;
  pin_t pin_sim_obj;
} chip_state_t;

void chip_timer_event(void *user_data) {
  chip_state_t *chip = (chip_state_t*)user_data;
  
  // Đọc tín hiệu từ nút nhấn (Giả lập việc có vật cản bay ngang qua)
  bool object_present = pin_read(chip->pin_sim_obj);

  // Xuất mức LOW nếu phát hiện vật cản, HIGH nếu không có
  if (object_present) {
    pin_write(chip->pin_out, LOW);
  } else {
    pin_write(chip->pin_out, HIGH);
  }
}

void chip_init(void) {
  chip_state_t *chip = malloc(sizeof(chip_state_t));

  chip->pin_out = pin_init("OUT", OUTPUT);
  // Khởi tạo chân giả lập vật cản, mặc định kéo xuống Mass
  chip->pin_sim_obj = pin_init("SIM_OBJ", INPUT_PULLDOWN);

  const timer_config_t timer_config = {
    .callback = chip_timer_event,
    .user_data = chip,
  };
  timer_t timer_id = timer_init(&timer_config);
  timer_start(timer_id, 50000, true);
}