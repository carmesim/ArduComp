enum PrgID
{
  sh = 0,
  yes = 1
};

static const char PrgNum = 2;

int (*PrgStarts[PrgNum])() = {
  sh_prg_start,
  yes_prg_start
  };

char argc, argv[16][16];
