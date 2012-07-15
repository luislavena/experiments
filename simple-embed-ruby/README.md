# simple-embed-ruby

An naive experiment on embedding Ruby (as static library) that works on
Linux and Windows (with GCC).

## Compile

To compile simple run `rake compile` on your console. it should generate
`embed-ruby` executable that you can play with.

## Tricks

It uses LD's ability to wrap around functions to give extra control to Ruby's
C API `rb_require` and `rb_require_safe` used by C extensions.

It also replaces global `require` with alternate one for extra control.

## Limitations

### Platforms

At this time only Linux and Windows has been proven to work. Apple's LD lacks
support for function wrapping (`--wrap`) so this can be used in that platform.

### RubyGems

Right now if Ruby was compiled with RubyGems (by default since 1.9.2),
`--disable-gems` needs to be used in the command line to avoid loading
RubyGems from a non-existing path caused by prelude initialization.

Until changes are made to the whole initialization, this is the only
workaround I can think of.

### Extensions and load path

Since it embeds Ruby library, `$LOAD_PATH` gets build relative to where the
executable is placed. For further testing you can place files in `lib` along
the executable.

## License

(The MIT License) applies to the code exposed in C files located in `src` and
any Ruby file used to build this project.

    Copyright (c) Luis Lavena

    Permission is hereby granted, free of charge, to any person obtaining
    a copy of this software and associated documentation files (the
    'Software'), to deal in the Software without restriction, including
    without limitation the rights to use, copy, modify, merge, publish,
    distribute, sublicense, and/or sell copies of the Software, and to
    permit persons to whom the Software is furnished to do so, subject to
    the following conditions:

    The above copyright notice and this permission notice shall be
    included in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
    IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
    CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
    TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
    SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Ruby's own license applies to Ruby library and API, also any 3rd party
library used along this code.
