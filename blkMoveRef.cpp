#include <blkMoveRef.hpp>
#include <string>



blk::Expr blk::move_ref( blk::Expr e, int nrw, int nrh) {
  // This raises a compilation error since MoveRef constructor is private
  // return std::make_shared<MoveRef>(symb,width,height,ref_width,ref_height); 
  return blk::Expr(new blk::MoveRef::MoveRef(e, nrw, nrh));
}

blk::MoveRef::MoveRef( blk::Expr e, int nrw, int nrh) :
    blk::Block::Block(e->getWidth(), e->getHeight(),nrw, nrh),
    exp(e)
   {}
   


void blk::MoveRef::printInBoundsLine(std::ostream& os, int i) const {
    exp->printLine(os, i+getRefHeight()-exp->getRefHeight());
    }


