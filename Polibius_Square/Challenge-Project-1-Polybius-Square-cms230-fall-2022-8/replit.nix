{ pkgs }: {
	deps = [
		pkgs.alpine
  pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}