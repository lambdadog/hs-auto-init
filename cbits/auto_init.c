extern void hs_init(int *argc, char **argv[]);
extern void hs_exit_nowait(void);

static void init(void) __attribute__((constructor));
static void init(void) {
  int argc = 0;
  hs_init(&argc, 0);
}

static void deinit(void) __attribute__((destructor));
static void deinit(void) {
  hs_exit_nowait();
}
