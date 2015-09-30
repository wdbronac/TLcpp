#pragma once

#include <blkBlock.hpp>

namespace blk {
Expr over(blk::Expr e1, blk::Expr e2);

class Over : public Block {
    private: 
        Expr exp1;
        Expr exp2;
    friend Expr over(blk::Expr e1, blk::Expr e2);

    Over(blk::Expr e1, blk::Expr e2);
    
int getSize(blk::Expr e1, blk::Expr e2);


    public: 

    Over()                            = delete;
    Over(const Over& cpy)            = delete;
    Over(Over&& cpy)                 = delete;
    Over& operator=(const Over& cpy) = delete;
    Over& operator=(Over&& cpy)      = delete;
    virtual ~Over() {}

    protected:

    virtual void printInBoundsLine(std::ostream& os, int i) const override;

    static void spePrint(std::ostream& os,const Expr& e1, int i, int L, int L2)  ;


  };

}
