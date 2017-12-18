//
//  tlb-table.h
//  Virtual Address Translator
//
//  Created by Railf on 12/5/17.
//  Copyright © 2017 Railf. All rights reserved.
//

#ifndef tlb_table_h
#define tlb_table_h

//                                  | VALID BIT | TAG | PHSYICAL PAGE # |
struct TLB
{
  bool    valid          = 0;
  int     tag            = 0;
  int     phsyical_page  = 0;
};

#endif /* tlb_table_h */
