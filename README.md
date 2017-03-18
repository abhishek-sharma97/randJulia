# randJulia

Uses the scilab api to call rand function from Julia language.
Should have the latest versions of Scilab and Julia installed.

run the following code after loading the file in contrib/toolbox_skeleton/sci_gateway/c/ :

  files=["sci_randJulia.c"];
  ilib_build('build_lib',['randJulia','sci_randJulia'],files,[]);
  exec loader.sce
  
  
