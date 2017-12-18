//
//  virtual-tlb.h
//  Virtual Address Translator
//
//  Created by Railf on 12/5/17.
//  Copyright © 2017 Railf. All rights reserved.
//

#ifndef virtual_tlb_h
#define virtual_tlb_h

union
{
    unsigned int address;
    
    struct
    {
        unsigned int offset:13;
        unsigned int index:1;
        unsigned int tag:6;
    } TLB;
    
    
    struct
    {
        unsigned int offset:13;
        unsigned int page:7;
    }table;
    
} v;

#endif /* virtual_tlb_h */
