
CC:= g++-4.4 `root-config --cflags --glibs`
Targets:= cutSetter

all: $(Targets)

NPDGCutSetterDict.cxx: NPDGCutSetter.h NPDGRunFile.h NPDGDefine.h NPDGCutSetterLinkDef.h
	rootcint -f $@ -c $^
cutSetter: NPDGCutSetter.cxx NPDGRunFile.cxx NPDGDefine.cxx NPDGCutSetterDict.cxx
	$(CC) -o $@ $^

NPDGAnalyzerDict.cxx: NPDGAnalyzer.h NPDGRunFile.h NPDGDefine.h NPDGAnalyzerLinkDef.h
	rootcint -f $@ -c $^

analyzer: NPDGAnalyzer.cxx NPDGRunFile.cxx NPDGDefine.cxx NPDGAnalyzerDict.cxx
	$(CC) -o $@ $^
