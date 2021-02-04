call plug#begin()
    Plug 'preservim/nerdtree'
call plug#end()

set tabstop=4
set shiftwidth=4
set expandtab
set nu
set numberwidth=1
highlight LineNr term=bold cterm=NONE ctermfg=LightGrey ctermbg=NONE gui=NONE guifg=DarkGrey guibg=NONE

map <C-n> :NERDTreeToggle <CR>
map <C-s> :w <CR>
map <C-q> :wq <CR>
