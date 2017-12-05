//
//  page-table.h
//  Virtual Address Translator
//
//  Created by Railf on 12/5/17.
//  Copyright © 2017 Railf. All rights reserved.
//

#ifndef page_table_h
#define page_table_h

template < class SETS, class PAGES >
class PageTable
{
private:
    int     phsyical_page;
    bool    resident;
};

#endif /* page_table_h */
