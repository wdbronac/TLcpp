#pragma once

#include <blkBlock.hpp>

namespace blk {
Expr beside(blk::Expr e1, blk::Expr e2);

class Beside : public Block {
    private: 
        Expr exp1;
        Expr exp2;
    friend Expr beside(blk::Expr e1, blk::Expr e2);

    Beside(blk::Expr e1, blk::Expr e2);

    public: 

    Beside()                            = delete;
    Beside(const Beside& cpy)            = delete;
    Beside(Beside&& cpy)                 = delete;
    Beside& operator=(const Beside& cpy) = delete;
    Beside& operator=(Beside&& cpy)      = delete;
    virtual ~Beside() {}

    protected:

    virtual void printInBoundsLine(std::ostream& os, int i) const override;



  };

}
