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

template < size_t INDEX >
struct PageTable
{
    int     phsyical_page[INDEX];
    bool    resident[INDEX];
};

#endif /* page_table_h */
