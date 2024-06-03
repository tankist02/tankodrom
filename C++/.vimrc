set exrc
"set nocompatible
syntax on
"set wildmenu
"set showmode
set background=dark
"set background=light

"set backspace=2
"set history=50
set autoindent
set smartindent

set smarttab
set tabstop=4
set shiftwidth=4
set expandtab

"set nomodeline
set number

"hi CursorLine cterm=NONE ctermbg=blue ctermfg=white
"set cursorline
"set cursorlineopt=number
"autocmd ColorScheme * highlight CursorLineNr cterm=bold term=bold gui=bold
"autocmd ColorScheme * highlight CursorLineNr

" Highlight only current line number
set cursorline
hi clear CursorLine
highlight CursorLineNr cterm=NONE ctermbg=blue ctermfg=white

"set tags=tags;/
set undofile
set undodir=/home/andrew/.vimundo

map <F2> :w<CR>
map <F3> :cp<CR>
map <F4> :cn<CR>
map <F5> :buffers<CR>:buffer<Space>
map <F6> :make -j8 clean<CR>
"build current file as program
" FreeBSD map <F7> :w<CR>:make -j`sysctl -n hw.ncpu` '%:r'<CR>
"map <F7> :w<CR>:make -j `nproc` '%:r' BUILD_TYPE=debug<CR>
"Save current buffer, build current prog, run it
map <F7> :w<CR>:make -j `nproc` '%:r' BUILD_TYPE=debug<CR>
map <F8> :w<CR>:make -j `nproc` '%:r' BUILD_TYPE=checked && ./'%:r'<CR>
map <F9> :w<CR>:make -j `nproc` '%:r' BUILD_TYPE=protect && ./'%:r'<CR>
map <F10> :w<CR>:make -j `nproc` '%:r' && ./'%:r'<CR>
"map <F11> :w<CR>:make -j `nproc` '%:r' && ./'%:r' BUILD_TYPE=debug<CR>
map <F12> :Ex<CR>

"au BufWritePost *.c,*.cpp,*.h silent! !~/bin/tags_update.sh &

set tags+=/data/dev/FP/C++

" To disable cscope overtaking ctags key Ctrl-\ comment out
" " set cst
" in /etc/vimrc
"
"   's'   symbol: find all references to the token under cursor
"   'g'   global: find global definition(s) of the token under cursor
"   'c'   calls:  find all calls to the function name under cursor
"   't'   text:   find all instances of the text under cursor
"   'e'   egrep:  egrep search for the word under cursor
"   'f'   file:   open the filename under cursor
"   'i'   includes: find files that include the filename under cursor
"   'd'   called: find functions that function under cursor calls

nmap <C-\>s :cs find s <C-R>=expand("<cword>")<CR><CR>	
nmap <C-\>g :cs find g <C-R>=expand("<cword>")<CR><CR>	
nmap <C-\>c :cs find c <C-R>=expand("<cword>")<CR><CR>	
nmap <C-\>t :cs find t <C-R>=expand("<cword>")<CR><CR>	
nmap <C-\>e :cs find e <C-R>=expand("<cword>")<CR><CR>	
nmap <C-\>f :cs find f <C-R>=expand("<cfile>")<CR><CR>	
nmap <C-\>i :cs find i ^<C-R>=expand("<cfile>")<CR>$<CR>
nmap <C-\>d :cs find d <C-R>=expand("<cword>")<CR><CR>	

" Using 'CTRL-spacebar' (intepreted as CTRL-@ by vim) then a search type
" makes the vim window split horizontally, with search result displayed in
" the new window.
"
" (Note: earlier versions of vim may not have the :scs command, but it
" can be simulated roughly via:
"    nmap <C-@>s <C-W><C-S> :cs find s <C-R>=expand("<cword>")<CR><CR>	

nmap <C-@>s :scs find s <C-R>=expand("<cword>")<CR><CR>	
nmap <C-@>g :scs find g <C-R>=expand("<cword>")<CR><CR>	
nmap <C-@>c :scs find c <C-R>=expand("<cword>")<CR><CR>	
nmap <C-@>t :scs find t <C-R>=expand("<cword>")<CR><CR>	
nmap <C-@>e :scs find e <C-R>=expand("<cword>")<CR><CR>	
nmap <C-@>f :scs find f <C-R>=expand("<cfile>")<CR><CR>	
nmap <C-@>i :scs find i ^<C-R>=expand("<cfile>")<CR>$<CR>	
nmap <C-@>d :scs find d <C-R>=expand("<cword>")<CR><CR>	


" Hitting CTRL-space *twice* before the search type does a vertical 
" split instead of a horizontal one (vim 6 and up only)
"
" (Note: you may wish to put a 'set splitright' in your .vimrc
" if you prefer the new window on the right instead of the left

nmap <C-@><C-@>s :vert scs find s <C-R>=expand("<cword>")<CR><CR>
nmap <C-@><C-@>g :vert scs find g <C-R>=expand("<cword>")<CR><CR>
nmap <C-@><C-@>c :vert scs find c <C-R>=expand("<cword>")<CR><CR>
nmap <C-@><C-@>t :vert scs find t <C-R>=expand("<cword>")<CR><CR>
nmap <C-@><C-@>e :vert scs find e <C-R>=expand("<cword>")<CR><CR>
nmap <C-@><C-@>f :vert scs find f <C-R>=expand("<cfile>")<CR><CR>	
nmap <C-@><C-@>i :vert scs find i ^<C-R>=expand("<cfile>")<CR>$<CR>	
nmap <C-@><C-@>d :vert scs find d <C-R>=expand("<cword>")<CR><CR>


