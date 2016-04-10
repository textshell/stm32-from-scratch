
void Reset_Handler();

extern char __stack_end;
extern void (* const vectors[])() __attribute__ ((section(".vectors"))) = {
                (void (*)())&__stack_end,
                Reset_Handler,
};

