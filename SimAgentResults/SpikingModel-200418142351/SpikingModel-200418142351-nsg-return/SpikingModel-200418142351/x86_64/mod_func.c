#include <stdio.h>
#include "hocdec.h"
extern int nrnmpi_myid;
extern int nrn_nobanner_;

extern void _kdr_reg(void);
extern void _leak_reg(void);
extern void _na_reg(void);

void modl_reg(){
  if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
    fprintf(stderr, "Additional mechanisms from files\n");

    fprintf(stderr," mod_nsgportal/kdr.mod");
    fprintf(stderr," mod_nsgportal/leak.mod");
    fprintf(stderr," mod_nsgportal/na.mod");
    fprintf(stderr, "\n");
  }
  _kdr_reg();
  _leak_reg();
  _na_reg();
}
