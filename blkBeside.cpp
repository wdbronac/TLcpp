#include <blkBeside.hpp>
#include <string>



blk::Expr blk::beside( blk::Expr e1, blk::Expr e2) {
  // This raises a compilation error since Beside constructor is private
  // return std::make_shared<Beside>(symb,width,height,ref_width,ref_height); 
  return blk::Expr(new blk::Beside::Beside(e1, e2));
}

blk::Beside::Beside( blk::Expr e1, blk::Expr e2) :
   blk::Block::Block(
           e1->getWidth() + e2->getWidth(),
           std::max(e1->getHeight(), e2->getHeight()),
           e1->getRefWidth(), 
           e2->getRefHeight()
           ),
          exp1(e1),
          exp2(e2)
   {}
   

void blk::Beside::printInBoundsLine(std::ostream& os, int i) const {
    exp1->blk::Block::printLine(os, i);
    exp2->blk::Block::printLine(os, i); 
}

