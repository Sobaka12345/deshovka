import os
from conan import ConanFile
from conan.tools.cmake import CMakeToolchain

class DemkiConan(ConanFile):
	settings = "os", "compiler", "build_type", "arch"
	requires = ["qt/6.7.1", "pfr/2.1.0"]
	generators = "CMakeDeps"

	def requirements(self):
		    self.requires("libxml2/2.11.4", override=True)

	def configure(self):
		os.environ["NOT_ON_C3I"] = "1"
		#SET os.environ["LLVM_INSTALL_DIR"] to llvm-config --prefix IF qtdoc BUILD DOES NOT WORK

		#Qt6 configuration
		# Enabled
		self.options["qt"]["gui"] = True
		self.options["qt"]["qtsvg"] = True
		self.options["qt"]["shared"] = True
		self.options["qt"]["openssl"] = True
		self.options["qt"]["widgets"] = True
		self.options["qt"]["with_pcre2"] = True
		self.options["qt"]["with_libpng"] = True
		self.options["qt"]["with_freetype"] = True
		self.options["qt"]["with_harfbuzz"] = True
		self.options["qt"]["with_doubleconversion"] = True

		self.options["qt"]["with_vulkan"] = True

		if self.settings.os == "Windows":
			    self.options["qt"]["opengl"] = "dynamic"
		elif self.settings.os == "Linux":
			    self.options["qt"]["opengl"] = "desktop"

		# Disabled
		#self.options["qt"]["opengl"] = "no"
		self.options["qt"]["qt3d"] = False
		self.options["qt"]["qtcoap"] = False
		self.options["qt"]["qtgrpc"] = False
		self.options["qt"]["qtmqtt"] = False
		self.options["qt"]["with_pq"] = False
		self.options["qt"]["qtopcua"] = False
		self.options["qt"]["qtscxml"] = False
		self.options["qt"]["qtcharts"] = False
		self.options["qt"]["qtgraphs"] = False
		self.options["qt"]["qtlottie"] = False
		self.options["qt"]["qtspeech"] = False
		self.options["qt"]["qt5compat"] = False
		self.options["qt"]["qtquick3d"] = False
		self.options["qt"]["qtsensors"] = False
		self.options["qt"]["qtwayland"] = False
		self.options["qt"]["qtwebview"] = False
		self.options["qt"]["with_dbus"] = False
		self.options["qt"]["with_glib"] = False
		self.options["qt"]["with_md4c"] = False
		self.options["qt"]["with_odbc"] = False
		self.options["qt"]["with_zstd"] = False
		self.options["qt"]["qtactiveqt"] = False
		self.options["qt"]["qtlocation"] = False
		self.options["qt"]["with_mysql"] = False
		self.options["qt"]["with_brotli"] = False
		self.options["qt"]["qtdatavis3d"] = False
		self.options["qt"]["qtserialbus"] = False
		self.options["qt"]["qtwebengine"] = False
		self.options["qt"]["qthttpserver"] = False
		self.options["qt"]["qtmultimedia"] = False
		self.options["qt"]["qtserialport"] = False
		self.options["qt"]["qtwebchannel"] = False
		self.options["qt"]["qtwebsockets"] = False
		self.options["qt"]["with_libjpeg"] = False
		self.options["qt"]["with_sqlite3"] = False
		self.options["qt"]["qtnetworkauth"] = False
		self.options["qt"]["qtpositioning"] = False
		self.options["qt"]["qtconnectivity"] = False
		self.options["qt"]["qtimageformats"] = False
		self.options["qt"]["qtquicktimeline"] = False
		self.options["qt"]["qtremoteobjects"] = False
		self.options["qt"]["qtlanguageserver"] = False
		self.options["qt"]["qtquick3dphysics"] = False
		self.options["qt"]["disabled_features"] = None
		self.options["qt"]["qtvirtualkeyboard"] = False
		self.options["qt"]["multiconfiguration"] = False
		self.options["qt"]["qtquickeffectmaker"] = False

	def generate(self):
		tc = CMakeToolchain(self)
		tc.presets_prefix = "conan-preset"
		tc.generate()

	def layout(self):
		# We make the assumption that if the compiler is msvc the
		# CMake generator is multi-config
		multi = True if self.settings.get_safe("compiler") == "msvc" else False
		if multi:
			self.folders.generators = os.path.join("generators")
		else:
			self.folders.generators = os.path.join("generators", str(self.settings.build_type))
