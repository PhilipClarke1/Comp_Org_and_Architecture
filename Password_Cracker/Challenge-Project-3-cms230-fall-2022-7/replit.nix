{ pkgs }: {
	deps = [
		pkgs.alpine
  pkgs.python39Full
  pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}