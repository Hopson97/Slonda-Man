
class Vector3:
    def __init__(self, x, y, z):
        self.x = float(x)
        self.y = float(y)
        self.z = float(z)
        
class Vector2:
    def __init__(self, x, y):
        self.x = float(x)
        self.y = float(y)
    

class ObjParser:
    '''Parses obj file in list'''
    
    def __init__(self):
        self.vert_coords = []
        self.tex_coords  = []
        self.normals     = []
        self.indices     = []
        
        self.out_vert_coords = []
        self.out_tex_coords  = []
        self.out_normals     = [] 
        
    def parse_file(self, file_name):
        self.get_data(file_name)
        self.sort_faces(file_name)
        self.finalise()
                    
    def get_data(self, file_name):
        with open(file_name) as inFile:
            for line in inFile:
                line = line.strip()
                line = line.split(" ")
                line_id = line[0]
                
                if line_id == "v":
                    x = line[1]
                    y = line[2]
                    z = line[3]
                    self.vert_coords.append(Vector3(x, y, z))
                    
                elif line_id == "vt":
                    x = line[1]
                    y = line[2]
                    self.tex_coords.append(Vector2(x, y))
                    
                elif line_id == "vn":
                    x = line[1]
                    y = line[2]
                    z = line[3]
                    self.normals.append(Vector3(x, y, z))
                    
                elif line_id == "f":
                    self.out_vert_coords = [None] * len(self.vert_coords)  * 3
                    self.out_tex_coords  = [None] * len(self.tex_coords)   * 2
                    self.out_normals     = [None] * len(self.normals)      * 3
                    
                    print(len(self.out_tex_coords))
                    print(len(self.tex_coords))
                    break
                    
    def sort_faces(self, file_name):
        with open(file_name) as inFile:
            for line in inFile:
                line = line.strip()
                line = line.split(" ")
                line_id = line[0]
                
                if line[0] != "f":
                    continue 
                    
                v1 = line[1].split("/")
                v2 = line[2].split("/")
                v3 = line[3].split("/")
                
                self.read_face(v1)
                self.read_face(v2)
                self.read_face(v3)
    
    def finalise(self):
        self.out_vert_coords = [None] * len(self.vert_coords) * 3
        
        ptr = 0
        for vertex in self.vert_coords:
            self.out_vert_coords[ptr] = vertex.x
            self.out_vert_coords[ptr] = vertex.y
            self.out_vert_coords[ptr] = vertex.z
        
                    
    def read_face(self, line):
        ptr = int(line[0]) - 1
        self.indices.append(ptr)
                    
        texs = self.tex_coords[int(line[1]) - 1]
        self.out_tex_coords[ptr * 2    ] = texs.x
        self.out_tex_coords[ptr * 2 + 1] = 1 - texs.y
        
        norm = self.normals[int(line[2]) - 1]
        self.out_normals[ptr * 3    ] = norm.x
        self.out_normals[ptr * 3 + 1] = norm.y
        self.out_normals[ptr * 3 + 2] = norm.z
        
                
                #else, it is a face!
                
            
                
if __name__ == "__main__":
    file_name = "test.obj"
    
    parser = ObjParser()
    parser.parse_file(file_name)
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    