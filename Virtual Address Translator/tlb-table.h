//
//  tlb-table.h
//  Virtual Address Translator
//
//  Created by Railf on 12/5/17.
//  Copyright © 2017 Railf. All rights reserved.
//

#ifndef tlb_table_h
#define tlb_table_h

template < size_t INDEX >
struct TLB
{
    bool    valid[INDEX];
    int     tag[INDEX];
    int     phsyical_page[INDEX];
};

#endif /* tlb_table_h */
