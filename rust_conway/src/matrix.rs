use std::ops::Index;


#[derive(Debug)]
pub struct Matrix <T> {
	pub v : Vec<T>,
   	pub width : usize,
    pub height : usize,
}

pub MatrixLine <T> {
	pub offset : usize,
	pub coeficient : usize,
	pub matrix : &Matrix,
} 

pub MutMatrixLine <T> {
	pub offset : usize,
	pub coeficient : usize,
	pub matrix : &mut Matrix,
}

impl <T: std::clone::Clone> Matrix <T> {
	pub fn new (w : usize, h : usize, val : T) -> Matrix<T> {
    	Matrix {
        	v: vec![val; w * h],
            width: w,
            height: h,
        }
	}

	pub fn row (&self, line_index : usize) -> Result<MatrixLine> {
		if line_index >= self.v.len {
			return err("Can't get an row at index because index is out of array.");
		} 

		ok( MatrixLine {
			offset: line_index,
			coeficient: 1,
			matrix: &self,
		})
	} 
}


impl<T> Index<(usize, usize)> for Matrix<T> {
    type Output = T;

    fn index(&self, index: (usize, usize)) -> &Self::Output {
        &self.v[index.0 + self.width * index.1]
    }
}
