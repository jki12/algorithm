import java.io.*;

class BinaryEditor {
    private static final String file = "program.bin";
    private static final byte[] program = { 0x49, (byte) 0xff, 0x4c, 0x00, (byte) 0x80 }; // add program.

    private static final int SIZE = 0x8000;

    public void memoryCopy(byte[] dest, byte[] source) {
        assert (dest.length >= source.length);

        for (int i = 0; i < source.length; ++i) dest[i] = source[i];
    }

    public void createBinFile() throws Exception {
        createBinFile(file, program);
    }

    public void createBinFile(final String file) throws Exception {
        createBinFile(file, program);
    }

    public void createBinFile(final byte[] program) throws Exception {
        createBinFile(file, program);
    }

    public void createBinFile(final String file, final byte[] program) throws Exception {
        var fs = new FileOutputStream(file);
        var binOut = new byte[SIZE];

        memoryCopy(binOut, program);

        binOut[0x7ffc] = 0x00;
        binOut[0x7ffd] = (byte) 0x80;

        fs.write(binOut);
        fs.close();
    }
}

public class Main {
    public static void main(String args[]) throws Exception {
        var editor = new BinaryEditor();

        {
            // 여기에 프로그램을 작성해 주세요. ex) byte[] program = { 0x49, (byte) 0xff, 0x4c, 0x00, (byte) 0x80 }; // add program.
        }

        editor.createBinFile();
    }
}