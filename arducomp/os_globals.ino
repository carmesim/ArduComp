enum PrgID
{
  sh = 0,
  yes = 1,
  pinmode = 2,
  digitalwrite = 3,
};

static const char PrgNum = 4;

int (*PrgStarts[PrgNum])() = {
  sh_prg_start,
  yes_prg_start,
  pinmode_prg_start,
  digitalwrite_prg_start
};

static const char _max_argc = 16;
static const char _max_argl = 16;

char argc, argv[_max_argc][_max_argl];
