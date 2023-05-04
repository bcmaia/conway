

use term_size::dimensions_stdout;
use crossterm::{cursor, execute};

/*
//extern crate unicode_segmentation;
//use unicode_segmentation::UnicodeSegmentation;

pub fn vertical_print (lines : &Vec<String>, position : i32) {
    let mut lines = lines
        .iter()
        .map(|s| {s.clone()})
        .collect::<Vec<String>>();

    //pad_strings(&mut lines);

    let (width, height) = dimensions_stdout().unwrap();

    println!("{}", (0..height).map(|_| {"\n"}).collect::<Vec<_>>().join(""));

    let mut x : usize = 0;
    let position =
        if position < 0 {0}
        else if position as usize >= lines.len() {lines.len() - 1}
        else {position as usize};

    for w in position..(width + position) {
        let mut y : usize = 0;

        if lines.len() <= w {break;}

        let s = &lines[w];
        // let s : String = lines[w]
        //    .graphemes(true)
        //    .rev() // Reverse the order of the grapheme iterator.
        //    .collect(); // Collect all the chars into a new owned String.

        for c in s.chars() {
            let cursor_pos = cursor::MoveTo(x as u16, y as u16);
            execute!(std::io::stdout(), cursor_pos).unwrap();

            let printed_c = match c {
                '━' => '┃',
                '┃' => '━',
                _ => c,
            };

            print!("{}", printed_c);

            y += 1;
        }

        x += 1;
    }

    println!("");
}


use termion::screen::IntoAlternateScreen;
use std::io::{Write, stdout};
use std::{thread, time};

fn main() {
	let (width, height) = dimensions_stdout().unwrap();

    {
        let mut screen = stdout().into_alternate_screen().unwrap();
        write!(screen, "Writing to alternate screen!").unwrap();
        screen.flush().unwrap();

        let ten_millis = time::Duration::from_millis(3000);
        let now = time::Instant::now();

        let (width, height) = dimensions_stdout().unwrap();

        let m = [' '; 5];

        let cursor_pos = cursor::MoveTo(1 as u16, 1 as u16);
        execute!(std::io::stdout(), cursor_pos).unwrap();

        print!("a");

        thread::sleep(ten_millis);

        assert!(now.elapsed() >= ten_millis);
    }

    println!("Writing to main screen.");





    let m = Matrix::<char>::new(width, height, ' ');
    
}


#[derive(Debug)]
pub struct Matrix <T> {
	pub v : Vec<T>,
	pub width : usize,
	pub height : usize,
}

impl <T: std::clone::Clone> Matrix <T> {
	pub fn new (w : usize, h : usize, val : T) -> Matrix<T> {
		Matrix {
			v: vec![val; w * h],
			width: w,
			height: h,
		}
	}
}

impl<T> Index<(usize, usize)> for Matrix<T> {
    type Output = T;

    fn index(&self, index: (usize, usize)) -> &Self::Output {
        &self.v[index.0 + self.width * index.1]
    }
}
*/
