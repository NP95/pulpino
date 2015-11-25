#include <gpio.h>

void set_pin_function(int pinnumber, int function) {
  volatile int old_function;
  int addr;


  old_function = *(volatile int*) (SOC_CTRL_PADFUN);
  old_function = old_function & (~(1 << pinnumber));
  old_function = old_function | (function << pinnumber);
  *(volatile int*) (SOC_CTRL_PADFUN) = old_function;
}

int  get_pin_function(int pinnumber) {
  volatile int old_function;
  old_function = *(volatile int*) (SOC_CTRL_PADFUN);
  old_function = (old_function >> pinnumber & 0x01);
  return old_function;
}

void set_gpio_pin_direction(int pinnumber, int direction) {
  volatile int old_dir;
  old_dir = *(volatile int*) (GPIO_REG_PADDIR);
  if (direction == 0)
    old_dir &= ~(1 << pinnumber);
  else
    old_dir |= 1 << pinnumber;
  *(volatile int*) (GPIO_REG_PADDIR) = old_dir;
}

int  get_gpio_pin_direction(int pinnumber) {
  volatile int old_dir;
  old_dir = *(volatile int*) (GPIO_REG_PADDIR);
  old_dir = (old_dir >> (pinnumber*2) & 0x01);
  return old_dir;

}

void set_gpio_pin_value(int pinnumber, int value) {
  volatile int v;
  v = *(volatile int*) (GPIO_REG_PADOUT);
  if (value == 0)
    v &= ~(1 << pinnumber);
  else
    v |= 1 << pinnumber;
  *(volatile int*) (GPIO_REG_PADOUT) = v;

}

int  get_gpio_pin_value(int pinnumber) {
  volatile int v;
  v = *(volatile int*) (GPIO_REG_PADIN);
  v = (v >> pinnumber) & 0x01;
  return v;
}

