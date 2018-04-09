# HeapBp
x64dbg plugin to set BPs on API's executed from out of module memory

This plugin is a simple plugin that registers the command "heapbp". The command is a wrapper that should be used like the regular BP command.

```heapbp apiName```

This command will set a BreakPoint on the API and also set a Breakpoint condition of `!mod.base([csp])`. This essentially creates a condition where
the breakpoint will only trigger if the API is being called from code that does not belong to a module (usually executing from the .text section of 
some module). My use case was to only trigger BP's being called from some shellcode or code running from Dynamically Allocated Memory. 
Might be useful to malware analyst or other users who want more control of where they want a BP to trigger from.

All feedback and suggestions welcomed.

How to use:
Fork the project
Build it
Copy heapbp to your plugins directory
Start x64dbg
type `heapbp api` in the commandline to set a heap breakpoint.
lift weights.

