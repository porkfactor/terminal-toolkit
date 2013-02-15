set(icu_FOUND TRUE)
set(icu_INCLUDE_DIR ${ICU_HOME}/include)
set(icu_LIB_DIR ${ICU_HOME}/lib)

set(icu_PARTS 
  common
  icudata
  icuin
  icuio
  icule
  iculx
  icutest
  icutu
  icuuc
)

if(WIN32)
  set(icu_icuin_LIBS icuin)
  set(icu_icuio_LIBS icuio)
  set(icu_icule_LIBS icule)
  set(icu_iculx_LIBS iculx)
  set(icu_icutest_LIBS "")
  set(icu_icutu_LIBS icutu)
  set(icu_icuuc_LIBS icuuc)
  
  set(icu_common_LIBS ${icu_icuin_LIBS} ${icu_icudata_LIBS} ${icu_icuuc_LIBS} ${icu_icuio_LIBS})
else()
  set(icu_icudata_LIBS icudata)
  set(icu_icuin_LIBS icui18n)
  set(icu_icuio_LIBS icuio)
  set(icu_icule_LIBS icule)
  set(icu_iculx_LIBS iculx)
  set(icu_icutest_LIBS icutest)
  set(icu_icutu_LIBS icutu)
  set(icu_icuuc_LIBS icuuc)
  
  set(icu_common_LIBS ${icu_icuin_LIBS} ${icu_icudata_LIBS} ${icu_icuuc_LIBS} ${icu_icuio_LIBS})
endif()

set(icu_LIBS 
  ${icu_icudata_LIBS}
  ${icu_icuin_LIBS}
  ${icu_icuio_LIBS}
  ${icu_icule_LIBS}
  ${icu_iculx_LIBS}
  ${icu_icutest_LIBS}
  ${icu_icutu_LIBS}
  ${icu_icuuc_LIBS}
)

