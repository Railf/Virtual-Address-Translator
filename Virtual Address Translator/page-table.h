//
//  page-table.h
//  Virtual Address Translator
//
//  Created by Railf on 12/5/17.
//  Copyright © 2017 Railf. All rights reserved.
//

#ifndef page_table_h
#define page_table_h

//                                  | PHSYICAL PAGE # | RESIDENT BIT |
struct PageTable
{
  int     phsyical_page  = 0;
  bool    resident       = 0;
};

#endif /* page_table_h */
