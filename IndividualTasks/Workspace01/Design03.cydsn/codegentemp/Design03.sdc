# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\DenysProjects\Workspace01\Design03.cydsn\Design03.cyprj
# Date: Thu, 02 Nov 2023 10:21:34 GMT
#set_units -time ns
create_clock -name {CyRouted1} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/dsi_in_0}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyLFClk} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyHFClk} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/hfclk}]]
create_clock -name {CySysClk} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/sysclk}]]
create_generated_clock -name {Clock_1} -source [get_pins {ClockBlock/hfclk}] -edges {1 12000001 24000001} [list [get_pins {ClockBlock/udb_div_0}]]


# Component constraints for C:\DenysProjects\Workspace01\Design03.cydsn\TopDesign\TopDesign.cysch
# Project: C:\DenysProjects\Workspace01\Design03.cydsn\Design03.cyprj
# Date: Thu, 02 Nov 2023 10:21:31 GMT
