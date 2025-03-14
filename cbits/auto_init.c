extern void hs_init(int *argc, char **argv[]);
extern void hs_exit_nowait(void);

static void init(void) __attribute__((constructor));
static void init(void) {
  hs_init(0, 0);
}

static void deinit(void) __attribute__((destructor));
static void deinit(void) {
  hs_exit_nowait();
}
