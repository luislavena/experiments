# refresh-env

One trick pony to force environment refresh under Windows.

## Wha?

When you modify environment variables under Windows, you normally need to
logout or restart the computer for those changes to take effect.

To avoid that, Windows offers a mechanism that notifies all running process
of environment changes to act accordingly.

The procedure is described in Microsoft support article [KB104011](http://support.microsoft.com/kb/104011).

## Why?

Certain tools like [WiX](http://wix.sourceforge.net/) do not broadcast this
notification when changing environment variables.

If you create a installer with WiX, you will need to use something like
PowerShell scripts, which might not be installed or allowed under some
systems.

Instead, this provides a simple, small application that does just that:
broadcast the environment changes to all open applications.

## License

I blatantly stole this from MSDN and Microsoft support, so cannot put a
copyright notice here.

I don't think I'm violating any law by using the sample code shown in
[KB104011](http://support.microsoft.com/kb/104011), but if you think that
I'm wrong, please use the [issues](https://github.com/luislavena/experiments/issues)
to let me know.
