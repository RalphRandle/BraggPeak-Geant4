cmake_minimum_required(VERSION 3.16)
project(BraggSim)

# =============================================================
# EN: Find Geant4 Package
# TR: Geant4 Paketini Bul
# =============================================================
# EN: Locates the Geant4 toolkit with User Interface (UI) and Visualization (VIS) components.
# TR: Geant4 araç kitini, Kullanýcý Arayüzü (UI) ve Görselleþtirme (VIS) bileþenleri ile birlikte bulur.
find_package(Geant4 REQUIRED ui_all vis_all)

# =============================================================
# EN: Geant4 Setup
# TR: Geant4 Kurulumu
# =============================================================
# EN: Loads standard Geant4 definitions and compiler flags.
# TR: Standart Geant4 tanýmlarýný ve derleyici bayraklarýný yükler.
include(${Geant4_USE_FILE})

# =============================================================
# EN: Source Code Discovery
# TR: Kaynak Kod Keþfi
# =============================================================
# EN: Automatically finds all source (.cc) and header (.hh) files in their respective directories.
# TR: Ýlgili klasörlerdeki tüm kaynak (.cc) ve baþlýk (.hh) dosyalarýný otomatik olarak bulur.
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

# =============================================================
# EN: Include Directories
# TR: Dahil Etme Dizinleri
# =============================================================
# EN: Adds the 'include' folder to the compiler's search path.
# TR: 'include' klasörünü derleyicinin arama yoluna ekler.
include_directories(${PROJECT_SOURCE_DIR}/include)

# =============================================================
# EN: Build Executable
# TR: Çalýþtýrýlabilir Dosyayý Oluþtur
# =============================================================
# EN: Creates the executable named 'bragg' from the main file and found sources.
# TR: Ana dosya ve bulunan kaynaklardan 'bragg' adýnda çalýþtýrýlabilir dosyayý oluþturur.
add_executable(bragg bragg.cc ${sources} ${headers})

# =============================================================
# EN: Linking
# TR: Baðlama Ýþlemi
# =============================================================
# EN: Links the necessary Geant4 libraries to the executable.
# TR: Gerekli Geant4 kütüphanelerini çalýþtýrýlabilir dosyaya baðlar.
target_link_libraries(bragg ${Geant4_LIBRARIES})

# =============================================================
# EN: Post-Build Actions
# TR: Derleme Sonrasý Ýþlemler
# =============================================================
# EN: Copies the visualization macro (vis.mac) to the build directory for easy execution.
# TR: Görselleþtirme makrosunu (vis.mac) kolay çalýþtýrma için build dizinine kopyalar.
file(COPY vis.mac DESTINATION ${CMAKE_BINARY_DIR})

# =============================================================
# EN: C++ Standard
# TR: C++ Standardý
# =============================================================
# EN: Enforces C++17 standard (Required for modern Geant4 versions).
# TR: C++17 standardýný zorunlu kýlar (Modern Geant4 sürümleri için gereklidir).
set(CMAKE_CXX_STANDARD 17)