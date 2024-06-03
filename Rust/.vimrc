set exrc
syntax on
set background=dark

set autoindent
set smartindent

set smarttab
set tabstop=4
set shiftwidth=4
set expandtab

"set nomodeline
set number

" Highlight only current line number
set cursorline
hi clear CursorLine
highlight CursorLineNr cterm=NONE ctermbg=blue ctermfg=white

set undofile
set undodir=/home/andrew/.vimundo

map <F2> :w<CR>
map <F3> :cp<CR>
map <F4> :cn<CR>
map <F5> :buffers<CR>:buffer<Space>
map <F6> :Cargo clean<CR>
map <F7> :Cargo build<CR>
map <F8> :Cargo clippy<CR>
"map <F9> :w<CR>:Cargo clippy<CR>
"map <F10> :w<CR>:make -j `nproc` '%:r' && ./'%:r'<CR>
map <F11> :Cargo run --release<CR>
"map <F12> :Ex<CR>

