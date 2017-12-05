//
//  tlb-table.h
//  Virtual Address Translator
//
//  Created by Railf on 12/5/17.
//  Copyright © 2017 Railf. All rights reserved.
//

#ifndef tlb_table_h
#define tlb_table_h

template < class SETS, class PAGES >
class TLB
{
private:
    bool    valid;
    int     tag;
    int     phsyical_page;
};

#endif /* tlb_table_h */
