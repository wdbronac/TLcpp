#pragma once

#include <blkBlock.hpp>

namespace blk {
Expr move_ref(blk::Expr e, int nrw, int nrh);

class MoveRef : public Block {
    private: 
        Expr exp;
    friend Expr move_ref(blk::Expr e, int nrw, int nrh);

    MoveRef(blk::Expr e, int nrw, int nrh);


    public: 

    MoveRef()                            = delete;
    MoveRef(const MoveRef& cpy)            = delete;
    MoveRef(MoveRef&& cpy)                 = delete;
    MoveRef& operator=(const MoveRef& cpy) = delete;
    MoveRef& operator=(MoveRef&& cpy)      = delete;
    virtual ~MoveRef() {}

    protected:

    virtual void printInBoundsLine(std::ostream& os, int i) const override;


  };

}
